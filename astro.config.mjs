// @ts-check
import { defineConfig } from 'astro/config';
import starlight from '@astrojs/starlight';


// https://astro.build/config
export default defineConfig({
	integrations: [
		starlight({
			title: "AnoTherK's shitpost",
			social: [{ icon: 'github', label: 'GitHub', href: 'https://github.com/AnoTherK-ATK' }, { icon: 'facebook', label: 'Facebook', href: 'https://www.facebook.com/anotherk.da' }],
			sidebar: [
				{
					label: 'About',
					items: [
						// Each item here is one entry in the navigation menu.
						{ label: 'Tôi là ai', slug: 'about/me' },
					],
				},
				{
					label: 'Reference',
					autogenerate: { directory: 'reference' },
				},
			],
			head: [
				{
					tag: 'script',
					attrs: {
						id: 'mathjax-script-config',
						type: 'text/javascript',
					},
					// Defines how MathJax finds and processes math in your content
					content: `
						window.MathJax = {
						tex: {
							inlineMath: [['$', '$']],
							displayMath: [['$$', '$$']],
							packages: {'[+]': ['ams']}
						},
						svg: {
							fontCache: 'global'
						}
						};
					`,
				},
				{
					tag: 'script',
					attrs: {
						id: 'mathjax-script',
						type: 'text/javascript',
						src: 'https://cdn.jsdelivr.net/npm/mathjax@3/es5/tex-svg.js',
						async: true,
					},
				},
				{
					tag: 'script',
					attrs: {
						type: 'module',
					},
					// Initializes MermaidJS and sets a theme that works well with Starlight
					content: `
						import mermaid from 'https://cdn.jsdelivr.net/npm/mermaid@10/dist/mermaid.esm.min.mjs';
						mermaid.initialize({
						startOnLoad: true,
						theme: 'dark', // Or 'default', 'neutral', 'forest'
						});
					`,
				},
			],
			customCss: ['./src/mathjax.css'],
		}),
	],
	site: 'https://AnoTherK-ATK.github.io',
	base: '/docs'
});
