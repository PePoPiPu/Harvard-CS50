document.addEventListener('DOMContentLoaded' () => {
    window.onSpotifyIframeApiReady = (IFrameAPI) => {
        let element = document.getElementById('embed-iframe');
        let options = {
            uri:'https://open.spotify.com/artist/4Z8W4fKeB5YxbusRsdQVPb?si=iKN9LibNQJKFqF14zOVMKQ'
           };
        let callback = (EmbedController) => {};
        IFrameAPI.createController(element, options, callback);
    };
})