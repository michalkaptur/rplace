import asyncio
import asyncio_dgram
import json


async def test_server_ping_pong(server):
    socket = await asyncio_dgram.connect((server.addr, server.port))
    ping = json.dumps({"type": "ping", "greeting": "Hey Joe!"})
    await socket.send(ping.encode("utf-8"))
    response, _sender = await socket.recv()
    response = json.loads(response.decode("utf-8"))
    assert response["type"] == "pong"
    assert response["greeting"] == "Hey Joe!"
    socket.close()  # TODO wrap
    assert False #just to check CI
