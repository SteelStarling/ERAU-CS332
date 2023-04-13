function requestJSON(filename, callback) {   
    var xobj = new XMLHttpRequest();
    xobj.overrideMimeType("application/json");
    xobj.open('GET', filename, true); // Replace 'my_data' with the path to your file
    xobj.onreadystatechange = function () {
          if (this.readyState == 4 && this.status == "200") {
            callback(xobj.responseText);
          }
    };
    xobj.send(null);  
 }
