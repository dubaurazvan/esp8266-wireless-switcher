var xmlhttp;
if (window.XMLHttpRequest) {// code for IE7+, Firefox, Chrome, Opera, Safari
    xmlhttp = new XMLHttpRequest();
} else {// code for IE6, IE5
    xmlhttp = new ActiveXObject("Microsoft.XMLHTTP");
}

switch(page) {
    case 'index':
        xmlhttp.open("GET","api/device-info.tpl", true);
        xmlhttp.setRequestHeader("Accept","application/json");
        xmlhttp.onreadystatechange = function() {
            if (xmlhttp.readyState==4 && xmlhttp.status==200) {
                var list = JSON.parse(xmlhttp.responseText);
                var html = '';
                for (var key in list) {
                    html += '<tr><td>' + key + '</td><td>' + list[key] + '</td></tr>';
                }
                currentHTML = document.getElementById('info-table').innerHTML;
                document.getElementById('info-table').innerHTML = currentHTML + html;
            }
        };
        xmlhttp.send();
    break;
    case 'gpio02':
        xmlhttp.open("GET","api/gpio02.tpl", true);
        xmlhttp.onreadystatechange = function() {
            if (xmlhttp.readyState==4 && xmlhttp.status==200) {
                document.getElementById("current-state").innerHTML = xmlhttp.responseText;
            }
        };
        xmlhttp.send();
        
        onButton = document.getElementById('on-button');
        onButton.onclick = function() {
            xmlhttp.open("POST","gpio02.cgi", true);
            xmlhttp.setRequestHeader("Content-type","application/x-www-form-urlencoded");
            xmlhttp.onreadystatechange = function() {
                if (xmlhttp.readyState==4 && xmlhttp.status==200) {
                    document.getElementById("current-state").innerHTML = xmlhttp.responseText;
                }
            };
            xmlhttp.send('value=1');
            return false;
        };

        onButton = document.getElementById('off-button');
        onButton.onclick = function() {
            xmlhttp.open("POST","gpio02.cgi", true);
            xmlhttp.setRequestHeader("Content-type","application/x-www-form-urlencoded");
            xmlhttp.onreadystatechange = function() {
                if (xmlhttp.readyState==4 && xmlhttp.status==200) {
                    document.getElementById("current-state").innerHTML = xmlhttp.responseText;
                }
            };
            xmlhttp.send('value=0');
            return false;
        };
    break;
}