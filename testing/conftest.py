import pytest
import asyncio
from types import SimpleNamespace


def pytest_addoption(parser):
    parser.addoption(
        "--server-path", action="store", default="../build/src/server/rplace_server"
    )


@pytest.fixture(scope="session")
def server_path(pytestconfig):
    return pytestconfig.getoption("server_path")


@pytest.fixture()
def server_address():
    return "127.0.0.1"


@pytest.fixture()
def server_port():
    return 4545


@pytest.fixture()
async def server(server_path, server_address, server_port):
    process = await asyncio.create_subprocess_exec(
        server_path,
        # stdout=asyncio.subprocess.PIPE,
    )  # TODO parametrize socket addr
    await asyncio.sleep(
        1
    )  # FIXME: server needs a moment to bind, replace with some retried ping message later on
    yield SimpleNamespace(process=process, port=server_port, addr=server_address)
    process.terminate()
    await process.wait()
    assert process.returncode == 0
