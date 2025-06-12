import React from 'react';
import { MapPin, Calendar, Award } from 'lucide-react';

export default function Profile() {
  return (
    <section className="py-16 px-6 bg-gradient-to-br from-slate-50 to-blue-50">
      <div className="max-w-6xl mx-auto">
        <div className="flex flex-col lg:flex-row items-center gap-12">
          <div className="lg:w-1/3">
            <div className="relative">
              <div className="w-80 h-80 rounded-full overflow-hidden shadow-2xl border-8 border-white">
                <img 
                  src="https://images.pexels.com/photos/3184306/pexels-photo-3184306.jpeg?auto=compress&cs=tinysrgb&w=800"
                  alt="エンジニアのプロフィール写真"
                  className="w-full h-full object-cover hover:scale-105 transition-transform duration-500"
                />
              </div>
              <div className="absolute -bottom-4 -right-4 bg-blue-500 text-white p-4 rounded-full shadow-lg">
                <Award className="w-8 h-8" />
              </div>
            </div>
          </div>
          
          <div className="lg:w-2/3 text-center lg:text-left">
            <h2 className="text-4xl font-bold text-slate-800 mb-4">
              こんにちは、私は
              <span className="text-blue-600 block mt-2">エンジニアです</span>
            </h2>
            
            <p className="text-xl text-slate-600 mb-6 leading-relaxed">
              組み込みシステム、バックエンド、フロントエンド開発に携わる
              フルスタックエンジニアです。革新的なソリューションの構築と
              技術的な課題の解決に情熱を注いでいます。
            </p>
            
            <div className="flex flex-col md:flex-row gap-6 text-slate-700">
              <div className="flex items-center justify-center lg:justify-start">
                <MapPin className="w-5 h-5 mr-2 text-blue-500" />
                <span>日本</span>
              </div>
              <div className="flex items-center justify-center lg:justify-start">
                <Calendar className="w-5 h-5 mr-2 text-blue-500" />
                <span>エンジニア歴 5年</span>
              </div>
            </div>
            
            <div className="mt-8">
              <button className="bg-gradient-to-r from-blue-500 to-cyan-500 text-white px-8 py-3 rounded-full hover:from-blue-600 hover:to-cyan-600 transition-all duration-300 transform hover:scale-105 shadow-lg">
                プロジェクトを見る
              </button>
            </div>
          </div>
        </div>
      </div>
    </section>
  );
}