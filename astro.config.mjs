// @ts-check
import { defineConfig } from 'astro/config';
import starlight from '@astrojs/starlight';
import remarkMath from 'remark-math';
import rehypeMathJax from 'rehype-mathjax';
import mermaid from 'astro-mermaid';

// https://astro.build/config
export default defineConfig({
	markdown: {
		remarkPlugins: [remarkMath],
		rehypePlugins: [rehypeMathJax],
	},
	integrations: [
		starlight({
			title: "AnoTherK's basement",
			social: [{ icon: 'github', label: 'GitHub', href: 'https://github.com/AnoTherK-ATK' }, { icon: 'facebook', label: 'Facebook', href: 'https://www.facebook.com/anotherk.da' }],
			sidebar: [
				{
					label: 'About',
					autogenerate: { directory: 'about' },
				},
				{
					label: 'Nhập môn lập trình',
					autogenerate: { directory: 'nmlt' },
				},
				{
					label: 'Cấu trúc dữ liệu và Giải thuật',
					autogenerate: { directory: 'dsa' },
				}
			],
			customCss: ['./src/mathjax.css'],
		}),
		mermaid({
			theme: 'dark',
			autoTheme: true,
			mermaidConfig: {
				flowchart: {
					curve: 'basis',
					padding: 15
				},
			}
		})
	],
	site: 'https://AnoTherK-ATK.github.io',
	base: '/'
});
