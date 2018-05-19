var ws = new WebSocket('ws://192.168.0.102:3000');
ws.onmessage = function (msg) {
    $("p").append(msg.info + msg.data + msg.status + '<br>');
};
$(document).ready(function () {
    $("#submit")
        .click(function () {
            ws.send(JSON.stringify({
                data: {
                    cid: ~~$("#data").val()
                },
                type: "hard",
                status: 1
            }));
        });
});
