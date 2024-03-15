# rplace protocol

JSON-encoded request-response protocol for rplace.

Keys are case-sensitive.

Note: at the moment the protocol in not versioned and definitely not backward-compatible.

## ping

### ping request

NO-OP message to check server connectivity. Might be tagged using `greeting`, server return the same in `pong` response.
```json
{
    "type": "ping",
    "greeting": "What's up, Doc?"
}
```
`greeting` could be optional someday

### pong response

Pong response which contains the same greeting as ping request.
```json
{
    "type" : "pong",
    "greeting" : "Hello darkness, my old friend"
}
```
