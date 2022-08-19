import asyncio
import asyncio_dgram


async def test_server_prints_rx_msg(server):
    socket = await asyncio_dgram.connect((server.addr, server.port))
    await socket.send(b"foo")
    out, _ = await server.process.communicate()
    assert b"foo" in out
    socket.close()  # TODO wrap
