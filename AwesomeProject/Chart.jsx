import React, { useState, useEffect } from 'react';
import { View, Text } from 'react-native';
import axios from 'axios';
import { LineChart } from 'react-native-chart-kit';

const Chart = () => {
  const [data, setData] = useState([]);

  useEffect(() => {
    axios.get('https://api.thingspeak.com/channels/2091425/feeds.json?api_key=P3ZPRWDOEHGGH7L5&results=10')
      .then(response => {
        setData(response.data.feeds.map(feed => parseFloat(feed.field1)));
      })
      .catch(error => console.log(error));
  }, []);

  return (
    <View>
      <Text>Chart of Field 1 Data</Text>
      <LineChart
        data={{
          labels: ['10', '9', '8', '7', '6', '5', '4', '3', '2', '1'],
          datasets: [
            {
              data,
            },
          ],
        }}
        width={350}
        height={220}
        chartConfig={{
          backgroundColor: '#e26a00',
          backgroundGradientFrom: '#fb8c00',
          backgroundGradientTo: '#ffa726',
          decimalPlaces: 2,
          color: (opacity = 1) => `rgba(255, 255, 255, ${opacity})`,
          labelColor: (opacity = 1) => `rgba(255, 255, 255, ${opacity})`,
          style: {
            borderRadius: 16,
          },
          propsForDots: {
            r: '6',
            strokeWidth: '2',
            stroke: '#ffa726',
          },
        }}
        bezier
        style={{
          marginVertical: 8,
          borderRadius: 16,
        }}
      />
    </View>
  );
};

export default Chart;
