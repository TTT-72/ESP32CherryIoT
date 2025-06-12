import React from 'react';
import { ExternalLink, Zap, Cpu, Wifi } from 'lucide-react';

export default function Gallery() {
  const projects = [
    {
      title: "IoTセンサーモジュール",
      description: "温度・湿度・気圧を測定するワイヤレスセンサー",
      image: "https://images.pexels.com/photos/163100/circuit-circuit-board-resistor-computer-163100.jpeg?auto=compress&cs=tinysrgb&w=800",
      icon: <Wifi className="w-6 h-6" />,
      tags: ["ESP32", "センサー", "無線通信"]
    },
    {
      title: "マイコン制御ボード",
      description: "産業用機器向けカスタムコントロールボード",
      image: "https://images.pexels.com/photos/343457/pexels-photo-343457.jpeg?auto=compress&cs=tinysrgb&w=800",
      icon: <Cpu className="w-6 h-6" />,
      tags: ["ARM", "リアルタイム", "産業用"]
    },
    {
      title: "電源管理システム",
      description: "効率的な電力制御とバッテリー管理",
      image: "https://images.pexels.com/photos/442154/pexels-photo-442154.jpeg?auto=compress&cs=tinysrgb&w=800",
      icon: <Zap className="w-6 h-6" />,
      tags: ["電源IC", "省電力", "効率化"]
    },
    {
      title: "プロトタイプ基板",
      description: "研究開発用の多機能テストボード",
      image: "https://images.pexels.com/photos/159298/printed-circuit-board-electronics-computer-159298.jpeg?auto=compress&cs=tinysrgb&w=800",
      icon: <Cpu className="w-6 h-6" />,
      tags: ["プロトタイプ", "開発", "テスト"]
    }
  ];

  return (
    <section className="py-16 px-6 bg-gradient-to-br from-slate-100 to-blue-100">
      <div className="max-w-6xl mx-auto">
        <div className="text-center mb-12">
          <h2 className="text-4xl font-bold text-slate-800 mb-4">開発したハードウェア</h2>
          <p className="text-xl text-slate-600">実際に設計・開発したプロジェクトの一部をご紹介します</p>
          <div className="w-24 h-1 bg-gradient-to-r from-blue-500 to-cyan-500 mx-auto rounded-full mt-4"></div>
        </div>

        <div className="grid md:grid-cols-2 gap-8">
          {projects.map((project, index) => (
            <div 
              key={index}
              className="bg-white rounded-2xl overflow-hidden shadow-lg hover:shadow-2xl transition-all duration-300 transform hover:-translate-y-2"
            >
              <div className="relative overflow-hidden">
                <img 
                  src={project.image}
                  alt={project.title}
                  className="w-full h-48 object-cover hover:scale-110 transition-transform duration-500"
                />
                <div className="absolute top-4 right-4 bg-white bg-opacity-90 p-2 rounded-full">
                  {project.icon}
                </div>
              </div>
              
              <div className="p-6">
                <h3 className="text-xl font-bold text-slate-800 mb-2">{project.title}</h3>
                <p className="text-slate-600 mb-4">{project.description}</p>
                
                <div className="flex flex-wrap gap-2 mb-4">
                  {project.tags.map((tag, tagIndex) => (
                    <span 
                      key={tagIndex}
                      className="px-3 py-1 bg-blue-100 text-blue-800 text-sm rounded-full"
                    >
                      {tag}
                    </span>
                  ))}
                </div>
                
                <button className="flex items-center text-blue-600 hover:text-blue-800 transition-colors duration-300">
                  <span className="mr-2">詳細を見る</span>
                  <ExternalLink className="w-4 h-4" />
                </button>
              </div>
            </div>
          ))}
        </div>
      </div>
    </section>
  );
}