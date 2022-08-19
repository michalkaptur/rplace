import asyncio

async def test_run_server(server_path):
    process = await asyncio.create_subprocess_exec(server_path)
    out, err = await process.communicate()
    assert process.returncode == 0