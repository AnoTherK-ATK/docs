// @ts-check
import { defineConfig } from 'astro/config';
import starlight from '@astrojs/starlight';
import remarkMath from 'remark-math';
import rehypeMathJax from 'rehype-mathjax';
import mermaid from 'astro-mermaid';
import starlightAutoSidebar from 'starlight-auto-sidebar';
import starlightThemeGalaxy from 'starlight-theme-galaxy';

// https://astro.build/config
export default defineConfig({
	markdown: {
		remarkPlugins: [remarkMath],
		rehypePlugins: [rehypeMathJax],
	},
	integrations: [
		starlight({
			plugins: [starlightAutoSidebar(), starlightThemeGalaxy()],
			title: "AnoTherK's basement",
			social: [{ icon: 'github', label: 'GitHub', href: 'https://github.com/AnoTherK-ATK/docs' }, { icon: 'facebook', label: 'Facebook', href: 'https://www.facebook.com/anotherk.da' }],
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
				},
			],
			customCss: [
				'./src/styles/mathjax.css',
				// load common weights so the theme can use 400/500/700 reliably
				'@fontsource/jetbrains-mono/400.css',
				'@fontsource/jetbrains-mono/700.css',
				'@fontsource/roboto/400.css',
				'@fontsource/roboto/700.css',
				'./src/styles/font.css',
				'./src/styles/font-override.css',
				'./src/styles/custom.css',
			],
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
		}),
	],
	site: 'https://AnoTherK-ATK.github.io',
	base: '/docs'
});
