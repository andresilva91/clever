/**
 * Clever programming language
 * Copyright (c) 2011-2012 Clever Team
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
 */

#include "compiler/value.h"
#include "modules/std/reflection/reflection.h"
#include "modules/std/reflection/reflectionpackage.h"
#include "modules/std/reflection/reflectionfunction.h"
#include "types/nativetypes.h"
#include "compiler/pkgmanager.h"

namespace clever { namespace packages { namespace std {

namespace reflection {
/**
 * get_type(object variable)
 * Returns the variable type name
 */
static CLEVER_FUNCTION(get_type) {
	CLEVER_RETURN_STR(CLEVER_ARG_TYPE_P(0)->getName());
}

} //  reflection

/**
 * Initializes Reflection module
 */
CLEVER_MODULE_INIT(Reflection) {
	/**
	 * Module classes
	 */
	BEGIN_DECLARE_CLASS();

	addClass(new reflection::ReflectionPackage);
	addClass(new reflection::ReflectionFunction);

	END_DECLARE();

	/**
	 * Module functions
	 */
	BEGIN_DECLARE_FUNCTION();

	addFunction(new Function("get_type",
		&CLEVER_NS_FNAME(reflection, get_type), CLEVER_STR))
		->setVariadic()
		->setMinNumArgs(1);

	END_DECLARE();
}

}}} // clever::packages::std
