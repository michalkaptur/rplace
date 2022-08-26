import asyncio
import asyncio_dgram


async def test_server_dummy_response(server):
    socket = await asyncio_dgram.connect((server.addr, server.port))
    await socket.send(b"foo")
    response = await socket.recv()
    assert b"bar" in response
    socket.close()  # TODO wrap
