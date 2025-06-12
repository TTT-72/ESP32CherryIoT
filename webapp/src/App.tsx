import React from 'react';
import Header from './components/Header';
import Profile from './components/Profile';
import Skills from './components/Skills';
import Gallery from './components/Gallery';
import Counter from './components/Counter';
import Footer from './components/Footer';

function App() {
  return (
    <div className="min-h-screen bg-white">
      <Header />
      <Profile />
      <Skills />
      <Gallery />
      <Counter />
      <Footer />
    </div>
  );
}

export default App;