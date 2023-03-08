window.onSpotifyIframeApiReady = (IFrameAPI) => {
    let element = document.getElementById('embed-iframe');
    let options = {
        width: '50%',
        height: '400',
        uri: 'spotify:artist:4Z8W4fKeB5YxbusRsdQVPb',
        };
    let callback = (EmbedController) => {};
    IFrameAPI.createController(element, options, callback);
    };
