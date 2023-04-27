import './App.css';
import { useRef } from 'react';
import Scene  from './Scene';

function MyComponent() {
  const inputRef = useRef(null);
}

function App() {
  return <div ref={inputRef}/>
}

export default App;
