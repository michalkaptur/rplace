import asyncio
import json


async def test_server_ping_pong(server_sock):
    ping = json.dumps({"type": "ping", "greeting": "Hey Joe!"})
    await server_sock.send(ping.encode("utf-8"))
    response, _sender = await server_sock.recv()
    response = json.loads(response.decode("utf-8"))
    assert response["type"] == "pong"
    assert response["greeting"] == "Hey Joe!"


async def test_sending_more_than_one_request(server_sock):
    async def ping_pong(greeting):
        ping = json.dumps({"type": "ping", "greeting": greeting})
        await server_sock.send(ping.encode("utf-8"))
        response, _sender = await server_sock.recv()
        response = json.loads(response.decode("utf-8"))
        assert response["type"] == "pong"
        assert response["greeting"] == greeting

    await ping_pong("Hey Joe!")
    await ping_pong("jungle boogie")
