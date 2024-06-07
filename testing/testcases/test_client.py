import asyncio
import asyncio_dgram
import json


async def test_client_transaction(server_address, server_port, client_path):
    srv_stub = await asyncio_dgram.bind((server_address, server_port))
    client = await asyncio.create_subprocess_exec(client_path)
    request, sender_addr = await srv_stub.recv()
    request = json.loads(request.rstrip(b"\x00"))
    assert request == {"type": "get_pixel", "position": {"x": 0, "y": 0}}
    await srv_stub.send(b"foo", sender_addr)
    return_code = await client.wait()
    assert return_code == len(b"foo")  # temporary, returns number of bytes received
