<html><head><title>WiFi connection</title>
<link rel="stylesheet" type="text/css" href="../css/style.css">
<script type="text/javascript" src="140medley.min.js"></script>
<script type="text/javascript">

var xhr=j();
var currAp="%currSsid%";

function createInputForAp(ap) {
	if (ap.essid=="" && ap.rssi==0) return;
	var div=document.createElement("div");
	div.id="apdiv";
	var input=document.createElement("input");
	input.type="radio";
	input.name="essid";
	input.value=ap.essid;
	if (currAp==ap.essid) input.checked="1";
	input.id="opt-"+ap.essid;
	var label=document.createElement("label");
	label.htmlFor="opt-"+ap.essid;
	label.textContent=ap.essid+" (rssi "+ap.rssi+")";
	div.appendChild(input);
	div.appendChild(label);
	return div;
}

function getSelectedEssid() {
	var e=document.forms.wifiform.elements;
	for (var i=0; i<e.length; i++) {
		if (e[i].type=="radio" && e[i].checked) return e[i].value;
	}
	return currAp;
}


function scanAPs() {
	xhr.open("GET", "wifiscan.cgi");
	xhr.onreadystatechange=function() {
		if (xhr.readyState==4 && xhr.status>=200 && xhr.status<300) {
			var data=JSON.parse(xhr.responseText);
			currAp=getSelectedEssid();
			if (data.result.inProgress=="0" && data.result.APs.length>1) {
				$("#aps").innerHTML="";
				for (var i=0; i<data.result.APs.length; i++) {
					if (data.result.APs[i].essid=="" && data.result.APs[i].rssi==0) continue;
					$("#aps").appendChild(createInputForAp(data.result.APs[i]));
				}
				window.setTimeout(scanAPs, 20000);
			} else {
				window.setTimeout(scanAPs, 3000);
			}
		}
	}
	xhr.send();
}


window.onload=function(e) {
	scanAPs();
};
</script>
</head>
<body>
<div id="main">
    <h1>Welcome to home automation interface</h1>
    <div id="menu">
        <ul>
            <li><a href="/index.tpl">Device Info</a></li>
            <li><a href="/gpio02.tpl">GPIO02</a></li>
            <li class="active"><a href="/wifi">WLAN settings.</a></li>
        </ul>
    </div>
    <div id="content">
        <p>Current WiFi mode: %WiFiMode%</p>
        <form name="wifiform" action="connect.cgi" method="post">
        <p>
        To connect to a WiFi network, please select one of the detected networks...<br>
        <div id="aps">Scanning...</div>
        <br>
        WiFi password, if applicable: <br />
        <input type="text" name="passwd" val="%WiFiPasswd%"> <br />
        <input type="submit" name="connect" value="Connect!">
        </p>
    </div>
    <div class="clear"></div>
    <div class="footer">
        <p align="right">by <a href="http://www.extragsm.com" target="_blank">ExtraGSM</a></p>
    </div>
</div>
</body>
</html>
