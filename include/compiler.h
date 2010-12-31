/*
 * Clever language
 * Copyright (c) 2010 Clever Team
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * $Id$
 */

#ifndef CLEVER_COMPILER_H
#define CLEVER_COMPILER_H

#include <boost/unordered_map.hpp>
#include "ast.h"
#include "opcodes.h"
#include "irbuilder.h"
#include "module.h"

namespace clever {

class Compiler {
public:
	typedef boost::unordered_map<const std::string, Function*> FunctionTable;

	Compiler() { }

	~Compiler();

	void Init(ast::TreeNode::nodeList&);
	void loadModules();
	void dumpAST();
	void buildIR();

	inline FunctionTable& get_functions() {
		return m_functions;
	}

	VM::OpcodeList* getOpcodes() {
		return m_builder.get_opcodes();
	}

	static void error(const char*);
	static bool checkCompatibleTypes(Value*, Value*);
	static ConstantValue* constantFolding(char, Value*, Value*);

	DISALLOW_COPY_AND_ASSIGN(Compiler);
private:
	/* AST nodes */
	ast::TreeNode::nodeList m_ast;
	/* IR Builder */
	IRBuilder m_builder;
	/* Module list */
	ModuleList m_modules;
	/* Global function table */
	FunctionTable m_functions;
};

} // clever

#endif // CLEVER_COMPILER_H
