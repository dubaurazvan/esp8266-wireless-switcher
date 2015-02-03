<head>
    <title>Home Automation</title>
    <link rel="stylesheet" type="text/css" href="css/style.css">
</head>
<body>
<div id="main">
    <h1>Welcome to home automation interface</h1>
    <div id="menu">
        <ul>
            <li><a href="index.tpl">Device Info</a></li>
            <li class="active"><a href="gpio02.tpl">GPIO02</a></li>
            <li><a href="/wifi">WLAN settings.</a></li>
        </ul>
    </div>
    <div id="content">
        If there is something connected to GPIO2, it's now <span id="current-state">--</span>.<br />
        Change the state:
        <a href="#" id="on-button">On</a>
        <a href="#" id="off-button">Off</a>
    </div>
    <div class="clear"></div>
    <div class="footer">
        <p align="right">by <a href="http://www.extragsm.com" target="_blank">ExtraGSM</a></p>
    </div>
</div>
<script type="text/javascript">var page = 'gpio02';</script>
<script type="text/javascript" src="js/script.js"></script>
</body>
</html>