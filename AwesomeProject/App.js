import { StatusBar } from 'expo-status-bar';
import { StyleSheet, Text, View } from 'react-native';
import React,{useState, useEffect} from 'react';
import Chart from './Chart'
export default function App() {
  const [data, setData] = useState([]);
  const [loading, setLoading] = useState(true);
  const [entrycode,setEntrycode] = useState(null);
  const url = "https://api.thingspeak.com/channels/2091425/feeds.json?api_key=P3ZPRWDOEHGGH7L5&results=1cr"
  useEffect(() => {
    fetch(url)
      .then((resp) => resp.json())
      .then((json) => setData(json))
      .catch((error) => console.error(error))
      .finally(() => setLoading(false));
  }, []);
  console.log(data);
  return (
    <View style={styles.container}>
      <Chart/>
      <StatusBar style="auto" />
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#fff',
    alignItems: 'center',
    justifyContent: 'center',
  },
  title: {
    fontSize: 30,
    fontWeight: "bold",
  },
});
