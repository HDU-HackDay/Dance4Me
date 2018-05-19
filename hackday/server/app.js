const Koa = require('koa');
const WebSocket = require('ws');

const WebSocketServer = WebSocket.Server;
const app = new Koa();

let server = app.listen(3000);
let wss = new WebSocketServer({
    server: server
});


wss.on('connection', (ws) => {
    console.log(`[SERVER] connection() ${ws}`);
    ws.send(JSON.stringify({
        info: 'Connection established!',
        status: 1
    }));
    ws.on('message', function incoming(message) {
        const data = JSON.parse(message);
        if (data.type === 'hard') {
            // hardware
            if (data.status === 1) {
                // success, push information
                wss.clients.forEach(function each(client) {
                    if (client != ws && client.readyState === WebSocket.OPEN) {
                        client.send(JSON.stringify({
                            data: data.data,
                            type: data.type,
                            status: data.status
                        }));
                    }
                });
            }else{
                // error occurrs
                wss.clients.forEach(function each(client) {
                    if (client != ws && client.readyState === WebSocket.OPEN) {
                        client.send(JSON.stringify({
                            data: '',
                            status: data.status
                        }));
                    }
                });
            }
        } else if (data.type === 'client') {
            // clinet
            ws.send(JSON.stringify({
                info: 'Connection established!',
                status: 1
            }));
        } else {
            ws.send(JSON.stringify({
                info: "Unsupported",
                status: -1
            }));
        }
    })
});

console.log(`server is listening at 3000`);