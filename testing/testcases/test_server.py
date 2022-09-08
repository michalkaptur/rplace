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

async def test_sending_more_than_one_request(server):
    socket = await asyncio_dgram.connect((server.addr, server.port))
    async def ping_pong(greeting):
        ping = json.dumps({"type": "ping", "greeting": greeting})
        await socket.send(ping.encode("utf-8"))
        response, _sender = await socket.recv()
        response = json.loads(response.decode("utf-8"))
        assert response["type"] == "pong"
        assert response["greeting"] == greeting
    await ping_pong("Hey Joe!")
    await ping_pong("jungle boogie")
    socket.close()  # todo wrap
