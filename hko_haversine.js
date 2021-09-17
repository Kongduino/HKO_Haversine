var hko={}
hko["Chek Lap Kok"]=[22.305582, 113.914124]
hko["Cheung Chau"]=[ 22.210121, 114.029108]
hko["HK Observatory"]=[22.302246, 114.174139]
hko["Lau Fau San"]=[22.469236, 113.983401]
hko["Peng Chau"]=[22.286995, 114.038209]
hko["Sha Tin"]=[22.390721, 114.202234]
hko["Shek Kong"]=[22.435531, 114.083070]
hko["Sheung Shui"]=[22.505465, 114.122356]
hko["Ta Kwu Ling"]=[22.538829, 114.160223]
hko["Tai Po"]=[22.444778, 114.168508]
hko["Waglan Island"]=[22.181801, 114.303081]
hko["Wetland Park"]=[22.470267, 114.005896]

Number.prototype.toRad = function() {
   return this * Math.PI / 180;
}
function haversine(lat1, lon1, lat2, lon2) {
  var R = 6371; // km
  var x1 = lat2-lat1;
  var dLat = x1.toRad();
  var x2 = lon2-lon1;
  var dLon = x2.toRad();
  var a = Math.sin(dLat/2) * Math.sin(dLat/2) +
    Math.cos(lat1.toRad()) * Math.cos(lat2.toRad()) *
    Math.sin(dLon/2) * Math.sin(dLon/2);
  var c = 2 * Math.atan2(Math.sqrt(a), Math.sqrt(1-a));
  var d = R * c;
  return Math.round((d + Number.EPSILON) * 100) / 100;
}

function closestDataPoint(lat1, lon1) {
  var d, dl=10000000, dp="", dpLat, dpLon;
  for(x in hko) {
    if(hko.hasOwnProperty(x)) {
      d=haversine(lat1, lon1, hko[x][0], hko[x][1]);
      if(d<dl) {
        dl=d;
        dp=x;
        dpLat=hko[x][0];
        dpLon=hko[x][1];
      }
    }
  }
  console.log(dp, "Lat:", dpLat, "Long:", dpLon, "Distance:", dl, "km");
}

closestDataPoint(22.279387, 114.010401);
