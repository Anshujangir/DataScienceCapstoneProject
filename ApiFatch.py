import requests
import json
import csv
import pandas as pd
url= "https://api.viotel.co/sensors/"

payload = json.dumps({
    "sensors": "viot00203-1",
    "epochmin": 1633405500,
    "epochmax": 1633410000
})

headers = {
    'Content-Type': 'application/json',
    'Content-Length':'',
    'x-Api-Key': 'Jl4I88ilnQ5ZIz4ll9JzdrarvUyiAKK8v7F5NbF8'
}

# make empty dataframe
df = pd.DataFrame()
response = requests.request("GET", url, headers=headers, data=payload)
data=json.loads(response.text)
body_data=data['body']
sensordata=json.loads(body_data)
for i in sensordata['sensordata']:
    df = df.append(i, ignore_index=True)

df = df.drop(['location1', 'measure_name', 'name','type'], axis=1)


date=[i.split(' ')[0] for i in df['time']]
time=[i.split(' ')[1] for i in df['time']]
time=[i[:-10] for i in time]

df['time']=[i+' '+j for i,j in zip(date,time)]
df = df.rename(columns={'time':'date/time','DisplayName':'name','measure_value::double':'measuredouble'})
cols=['date/time','name','measuredouble']
df=df[cols]
df['measuredouble1']=''
df['measuredouble2']=''
df['measuredouble1']=df['measuredouble']
df['measuredouble2']=df['measuredouble']
df['measuredouble'][1]=0
df['measuredouble'][2]=0
df['measuredouble1'][0]=0
df['measuredouble2'][0]=0
df['measuredouble1'][2]=0
df['measuredouble2'][1]=0

# make type int of measuredouble, measuredouble1, measuredouble2
df['measuredouble']=df['measuredouble'].astype(float)
df['measuredouble1']=df['measuredouble1'].astype(float)
df['measuredouble2']=df['measuredouble2'].astype(float)

df['measuredouble'][0]=sum(df['measuredouble'])
df['measuredouble1'][0]=sum(df['measuredouble1'])
df['measuredouble2'][0]=sum(df['measuredouble2'])

# remove 2nd and 3rd row
df=df.drop(df.index[[1,2]])
# make csv file
df.to_csv('data.csv', index=False)
