import React from 'react';
import { Code, Server, Cpu, Database, Globe, Settings } from 'lucide-react';

export default function Skills() {
  const skillCategories = [
    {
      title: "組み込み開発",
      icon: <Cpu className="w-8 h-8" />,
      skills: ["マイコン制御", "リアルタイムOS", "ハードウェア設計", "プロトタイピング"],
      color: "from-purple-500 to-pink-500"
    },
    {
      title: "バックエンド",
      icon: <Server className="w-8 h-8" />,
      skills: ["API設計", "データベース", "サーバー管理", "クラウド"],
      color: "from-green-500 to-teal-500"
    },
    {
      title: "フロントエンド",
      icon: <Globe className="w-8 h-8" />,
      skills: ["UI/UX設計", "レスポンシブ", "SPA開発", "モダンJS"],
      color: "from-blue-500 to-cyan-500"
    }
  ];

  const languages = [
    { name: "C++", level: 90, color: "bg-red-500" },
    { name: "Python", level: 85, color: "bg-yellow-500" },
    { name: "JavaScript", level: 80, color: "bg-blue-500" },
    { name: "TypeScript", level: 75, color: "bg-indigo-500" }
  ];

  return (
    <section className="py-16 px-6 bg-white">
      <div className="max-w-6xl mx-auto">
        <div className="text-center mb-12">
          <h2 className="text-4xl font-bold text-slate-800 mb-4">スキル & 専門分野</h2>
          <div className="w-24 h-1 bg-gradient-to-r from-blue-500 to-cyan-500 mx-auto rounded-full"></div>
        </div>

        {/* スキルカテゴリー */}
        <div className="grid md:grid-cols-3 gap-8 mb-16">
          {skillCategories.map((category, index) => (
            <div 
              key={index}
              className="bg-white rounded-2xl p-8 shadow-lg hover:shadow-xl transition-all duration-300 transform hover:-translate-y-2 border border-slate-100"
            >
              <div className={`w-16 h-16 rounded-full bg-gradient-to-r ${category.color} flex items-center justify-center text-white mb-6 mx-auto`}>
                {category.icon}
              </div>
              <h3 className="text-xl font-bold text-slate-800 text-center mb-4">{category.title}</h3>
              <ul className="space-y-2">
                {category.skills.map((skill, skillIndex) => (
                  <li key={skillIndex} className="text-slate-600 flex items-center">
                    <div className="w-2 h-2 bg-blue-400 rounded-full mr-3"></div>
                    {skill}
                  </li>
                ))}
              </ul>
            </div>
          ))}
        </div>

        {/* プログラミング言語 */}
        <div className="bg-gradient-to-br from-slate-50 to-blue-50 rounded-2xl p-8">
          <h3 className="text-2xl font-bold text-slate-800 text-center mb-8">プログラミング言語</h3>
          <div className="grid md:grid-cols-2 gap-6">
            {languages.map((lang, index) => (
              <div key={index} className="bg-white rounded-xl p-6 shadow-md">
                <div className="flex justify-between items-center mb-3">
                  <span className="font-semibold text-slate-800">{lang.name}</span>
                  <span className="text-slate-600">{lang.level}%</span>
                </div>
                <div className="w-full bg-slate-200 rounded-full h-3">
                  <div 
                    className={`${lang.color} h-3 rounded-full transition-all duration-1000 ease-out`}
                    style={{ width: `${lang.level}%` }}
                  ></div>
                </div>
              </div>
            ))}
          </div>
        </div>
      </div>
    </section>
  );
}