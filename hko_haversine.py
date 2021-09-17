import math

hko={}
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

def toRad(x):
  return x * 3.141592653 / 180

def haversine(lat1, lon1, lat2, lon2):
  R = 6371
  x1 = lat2-lat1
  dLat = toRad(x1)
  x2 = lon2-lon1
  dLon = toRad(x2)
  a = math.sin(dLat/2) * math.sin(dLat/2) + math.cos(toRad(lat1)) * math.cos(toRad(lat2)) * math.sin(dLon/2) * math.sin(dLon/2)
  c = 2 * math.atan2(math.sqrt(a), math.sqrt(1-a))
  d = R * c
  return round((d + 2.220446049250313e-16) * 100) / 100

def closestDataPoint(lat1, lon1):
  dl=10000000
  dp=""
  dpLat=0
  dpLon=0
  for x in hko.keys():
    d=haversine(lat1, lon1, hko[x][0], hko[x][1])
    if(d<dl):
      dl=d
      dp=x
      dpLat=hko[x][0]
      dpLon=hko[x][1]
  print(dp + " Lat: " + str(dpLat) + ", Long: " + str(dpLon) + ". Distance: " + str(dl) + "km")


closestDataPoint(22.279387, 114.010401)
