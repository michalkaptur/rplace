import pytest
import asyncio
import asyncio_dgram
from types import SimpleNamespace


def pytest_addoption(parser):
    parser.addoption(
        "--server-path", action="store", default="../build/src/server/rplace_server"
    )


def pytest_addoption(parser):
    parser.addoption(
        "--client-path", action="store", default="../build/src/client/rplace_client"
    )


@pytest.fixture(scope="session")
def server_path(pytestconfig):
    return pytestconfig.getoption("server_path")


@pytest.fixture(scope="session")
def client_path(pytestconfig):
    return pytestconfig.getoption("client_path")


@pytest.fixture()
def server_address():
    return "127.0.0.1"


@pytest.fixture()
def server_port():
    return 4545


@pytest.fixture()
async def server(server_path):
    process = await asyncio.create_subprocess_exec(
        server_path,
        # stdout=asyncio.subprocess.PIPE,
    )  # TODO parametrize socket addr
    await asyncio.sleep(
        1
    )  # FIXME: server needs a moment to bind, replace with some retried ping message later on
    yield process
    process.terminate()
    await process.wait()
    assert process.returncode == 0


@pytest.fixture
async def server_sock(server, server_address, server_port):
    socket = await asyncio_dgram.connect((server_address, server_port))
    yield socket
    socket.close()
