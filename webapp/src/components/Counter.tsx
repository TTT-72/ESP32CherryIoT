import React, { useState } from 'react';
import { RotateCcw, Trophy } from 'lucide-react';

export default function Counter() {
  const [count, setCount] = useState(0);
  const [isRotating, setIsRotating] = useState(false);

  const handleClick = () => {
    setCount(count + 1);
    setIsRotating(true);
    setTimeout(() => setIsRotating(false), 600);
  };

  const resetCounter = () => {
    setCount(0);
    setIsRotating(true);
    setTimeout(() => setIsRotating(false), 600);
  };

  return (
    <section className="py-16 px-6 bg-gradient-to-r from-slate-900 via-blue-900 to-slate-900 text-white">
      <div className="max-w-4xl mx-auto text-center">
        <div className="mb-8">
          <h2 className="text-4xl font-bold mb-4">インタラクティブカウンター</h2>
          <p className="text-xl text-slate-300">クリックして楽しんでください！</p>
        </div>

        <div className="bg-white bg-opacity-10 backdrop-blur-lg rounded-3xl p-12 shadow-2xl border border-white border-opacity-20">
          <div className="mb-8">
            <div 
              className={`inline-block p-8 rounded-full bg-gradient-to-r from-blue-500 to-cyan-500 shadow-lg cursor-pointer transform transition-all duration-300 hover:scale-110 ${
                isRotating ? 'animate-spin' : ''
              }`}
              onClick={handleClick}
            >
              <Trophy className="w-16 h-16 text-white" />
            </div>
          </div>

          <div className="mb-8">
            <div className="text-6xl font-bold mb-4 bg-gradient-to-r from-yellow-400 to-orange-400 bg-clip-text text-transparent">
              {count}
            </div>
            <p className="text-xl text-slate-300">
              {count === 0 && "まだクリックされていません"}
              {count === 1 && "初回クリック！"}
              {count > 1 && count < 10 && "順調にクリック中"}
              {count >= 10 && count < 50 && "素晴らしいクリック数！"}
              {count >= 50 && count < 100 && "クリックマスター！"}
              {count >= 100 && "クリック界の伝説！"}
            </p>
          </div>

          <div className="flex flex-col sm:flex-row gap-4 justify-center">
            <button
              onClick={handleClick}
              className="bg-gradient-to-r from-blue-500 to-cyan-500 text-white px-8 py-4 rounded-full hover:from-blue-600 hover:to-cyan-600 transition-all duration-300 transform hover:scale-105 shadow-lg text-lg font-semibold"
            >
              クリック！
            </button>
            
            <button
              onClick={resetCounter}
              className="bg-gradient-to-r from-slate-600 to-slate-700 text-white px-8 py-4 rounded-full hover:from-slate-700 hover:to-slate-800 transition-all duration-300 transform hover:scale-105 shadow-lg text-lg font-semibold flex items-center justify-center"
            >
              <RotateCcw className="w-5 h-5 mr-2" />
              リセット
            </button>
          </div>

          {count > 0 && (
            <div className="mt-8 text-sm text-slate-400">
              <div className="flex justify-center space-x-8">
                <div>
                  <span className="block text-2xl font-bold text-blue-400">{count}</span>
                  <span>総クリック数</span>
                </div>
                <div>
                  <span className="block text-2xl font-bold text-green-400">{Math.floor(count / 10)}</span>
                  <span>レベル</span>
                </div>
                <div>
                  <span className="block text-2xl font-bold text-yellow-400">{count * 10}</span>
                  <span>ポイント</span>
                </div>
              </div>
            </div>
          )}
        </div>
      </div>
    </section>
  );
}