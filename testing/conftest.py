import pytest 

def pytest_addoption(parser):
    parser.addoption("--server-path", action="store", default="../build/src/server/rplace_server")

@pytest.fixture(scope="session")
def server_path(pytestconfig):
    return pytestconfig.getoption("server_path")