# -*- coding:utf-8 -*- 
import os, re
import HTMLParser
import codecs

parser = HTMLParser.HTMLParser()
texfile = codecs.open("solutions.tex", "w", "utf-8")
texspecific = {'#':'\\#', '$': '\\$', '%': '\\%', '{': '\\{', '}': '\\}', '~': '\\~{}', '^': '\\^{}', '_': '\_'}

def getPart(html, startstr, endstr):
	start = html.find(startstr)
	end = html.find(endstr, start + len(startstr))
	return parser.unescape(html[start + len(startstr): end].decode('utf8'))

def text2tex(text):
	text = text.strip('\n')

	# specific
	# text = text.replace('\\', '\\\\\\')
	for key, value in texspecific.items():
		text = text.replace(key, value)
	# text = text.replace('\\\\\\', '$\\backslasb$')
	
	# <b></b>, <i></i>
	text = re.sub(r'<b>(.+?)</b>', r'\\textbf{\1}', text) 
	text = re.sub(r'<i>(.+?)</i>', r'\\emph{\1}', text) 

	# <ul><li></li><ul>
	ultext = re.compile(r'<li>.+?</li>', re.S).findall(text)
	if ultext:
		text = re.compile(r'<ul>.+?</ul>', re.S).sub('', text)
		text += '\\begin{itemize}\n'
		for li in ultext:
			text += '\\item ' + li[4:-5] + '\n'
		text += '\end{itemize}\n'

	# <br />
	text = text.replace('<br />', '\n\n')

	# <code></code>
	text = re.sub(r'<code>(.+?)</code>', r'\\textbf{\1}', text)

	# <pre></pre>
	prere = re.compile(r'<pre>(.+?)</pre>', re.S)
	text = prere.sub(r'\\begin{verbatim}\1\\end{verbatim}', text)
	
	# <.*>
	text = re.sub(r'<.+?>', '', text).strip()

	# <, >
	text = text.replace("<", "$<$").replace(">", "$>$")

	return text

def getProblem(html):
	html = getPart(html, '<div class="question-content">\n              <p>', ' </div>')
	# print html
	parare = re.compile(r'<p>.+?</p>', re.S) 
	paras = parare.findall(html)
	html = parare.sub('', html)
	examples = re.compile(r'<pre>.+?</pre>', re.S).findall(html)
	desp = ""
	for para in paras:
		desp += text2tex(para[3:-4]) + "\n\n"
	for example in examples:
		desp += "\\begin{verbatim}\n" + example[5:-6].strip('\n\r\t') + "\n\\end{verbatim}\n"
	return desp

def getInitCode(html, language = "C++"):
	return getPart(html, language + "', 'defaultCode': '", "' }").decode('unicode-escape')

def writeTexHead():
	texhead = '''
\documentclass{article}
\usepackage{CJK}
\usepackage[top=1in, bottom=1in, left=1.2in, right=1.2in]{geometry}
\usepackage{multirow}
\usepackage{indentfirst}
\usepackage{booktabs}
\usepackage{listings}
\usepackage{graphicx}
\usepackage{amsmath}
\usepackage{color}
\usepackage[colorlinks,linkcolor=blue]{hyperref}
\definecolor{gray}{rgb}{0.5,0.5,0.5}
\usepackage{listings}
\lstset{numbers=left, 
		basicstyle=\\small\\ttfamily,
		language=C++, 
		breaklines, 
		extendedchars=false, 
		keywordstyle=\color{blue}\\bfseries,
		frame=none,
		tabsize=4,
		commentstyle=\color{gray},
		stringstyle=\emph\\bfseries,
		columns=flexible
		}
\\begin{document}
\\begin{CJK*}{UTF8}{gkai}
\CJKindent
\\title{Solutions of leetcode}
\\author{hustsxh@gmail.com}

\maketitle

	'''
	print >> texfile, texhead

def writeTexTail():
	textail = '''
\end{CJK*}
\end{document} '''
	print >> texfile, textail

def writeProblem(name, desp, initcode, tags):
	print name
	solution, code = "", ""
	try:
		solution = open("solution/" + name + ".txt").read().decode('utf8')
	except:
		pass
	try:
		code = open("code/" + name + ".cpp").read().decode('utf8')
	except:
		pass
	print >> texfile, "\n\\subsection{", name, "}\n\\label{", name, "}"
	# print >> texfile, "\\begin{verbatim}\n" + desp + "\n\\end{verbatim}\n"
	print >> texfile, "\n\\subsubsection*{Problem Description}\n", desp

	# print >> texfile, "\\begin{lstlisting}\n", initcode, "\n\\end{lstlisting}"

	print >> texfile, "\\textbf{Tags: }"
	for i in range(len(tags)):
		if i == len(tags) - 1:
			print >> texfile, "\\hyperref[", tags[i], "]{", tags[i], "}"
		else:
			print >> texfile, "\\hyperref[", tags[i], "]{", tags[i], "}, ", 
	
	print >> texfile, "\n\n\\rightline{\\href{https://oj.leetcode.com/problems/" + name.lower().replace(' ', '-') + "/}{Submit}}"
	
	if solution:
		print >> texfile, "\n\\subsubsection*{Solution}\n", solution
	else:
		print >> texfile, "\n\\subsubsection*{Solution}\n", u"水题"

	print >> texfile, "\n\\subsubsection*{Code}\n\\begin{lstlisting}\n", code, "\n\\end{lstlisting}\n"

def getTags(html):
	tags = getPart(html, "Show Tags</div>", "</div>")
	# print tags
	tags = re.findall(r'>(.+?)</a>', tags)
	return tags

def writeTagsClassify():
	tagset = {}
	for filename in os.listdir("problems/"):
		name = "".join(filename.split('.')[:-1])
		tags = getTags(open("problems/" + filename).read())
		for tag in tags:
			if tag not in tagset:
				tagset[tag] = []
			tagset[tag].append(name)
	print tagset
	print >> texfile, "\\section{Problems Classify}"
	for tag, problems in tagset.items():
		print >> texfile, "\n\\subsection*{", tag, "}\n\\label{", tag, "}" 
		for i in range(len(problems)):
			if i == len(problems) - 1:
				print >> texfile, "\\hyperref[", problems[i], "]{", problems[i], "}"
			else:
				print >> texfile, "\\hyperref[", problems[i], "]{", problems[i], "},"

if __name__ == '__main__':
	writeTexHead()
	writeTagsClassify()
	
	print >> texfile, "\\section{Solutions of leetcode algorithm problems}"
	for filename in os.listdir("problems/"):
		name = filename.split(".")[0]
		html = open("problems/" + filename).read()
		desp = getProblem(html)
		initcode = getInitCode(html)
		tags = getTags(html)
		writeProblem(name = name, desp = desp, initcode = initcode, tags = tags)

	writeTexTail()


