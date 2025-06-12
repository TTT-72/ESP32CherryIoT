import React from 'react';
import { Heart, Code2, Mail, Phone, MapPin } from 'lucide-react';

export default function Footer() {
  return (
    <footer className="bg-slate-900 text-white py-12 px-6">
      <div className="max-w-6xl mx-auto">
        <div className="grid md:grid-cols-3 gap-8 mb-8">
          <div>
            <div className="flex items-center mb-4">
              <Code2 className="w-6 h-6 mr-2 text-blue-400" />
              <h3 className="text-xl font-bold">Engineer Portfolio</h3>
            </div>
            <p className="text-slate-400 mb-4">
              技術への情熱と革新的なソリューションを通じて、
              より良い未来を創造していきます。
            </p>
          </div>
          
          <div>
            <h3 className="text-lg font-semibold mb-4">専門分野</h3>
            <ul className="space-y-2 text-slate-400">
              <li>• 組み込みシステム開発</li>
              <li>• バックエンドアーキテクチャ</li>
              <li>• フロントエンド開発</li>
              <li>• ハードウェア設計</li>
            </ul>
          </div>
          
          <div>
            <h3 className="text-lg font-semibold mb-4">お問い合わせ</h3>
            <div className="space-y-3 text-slate-400">
              <div className="flex items-center">
                <Mail className="w-4 h-4 mr-2" />
                <span>engineer@example.com</span>
              </div>
              <div className="flex items-center">
                <Phone className="w-4 h-4 mr-2" />
                <span>+81-90-xxxx-xxxx</span>
              </div>
              <div className="flex items-center">
                <MapPin className="w-4 h-4 mr-2" />
                <span>東京, 日本</span>
              </div>
            </div>
          </div>
        </div>
        
        <div className="border-t border-slate-800 pt-8 text-center">
          <p className="text-slate-400 flex items-center justify-center">
            Made with <Heart className="w-4 h-4 mx-2 text-red-500" fill="currentColor" /> by Engineer
          </p>
          <p className="text-slate-500 text-sm mt-2">
            © 2024 Engineer Portfolio. All rights reserved.
          </p>
        </div>
      </div>
    </footer>
  );
}