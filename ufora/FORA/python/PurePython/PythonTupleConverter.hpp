/***************************************************************************
   Copyright 2015 Ufora Inc.

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
****************************************************************************/
#pragma once

#include "../../../core/PolymorphicSharedPtr.hpp"
#include "../../../core/math/Nullable.hpp"

class Expression;
class ImplValContainer;
template<class T>
class ImmutableTreeVector;

namespace Fora {
class PythonAstExpr;
class PythonAstExpr_TupleType;
}

namespace Fora {

class PythonTupleConverter:
        public PolymorphicSharedPtrBase<PythonTupleConverter> {
public:
    virtual Expression convertPyTuple(
        const Fora::PythonAstExpr_TupleType& tupleExpr,
        const std::function<Expression(const PythonAstExpr&)>& 
            convertPythonAstExpressionToFora
        ) const = 0;

    virtual ImplValContainer createTuple(
        const ImmutableTreeVector<ImplValContainer>& tupleElements
        ) const;

    virtual Expression createTupleExpression(
        const Expression& rawTupleExpression
        ) const = 0;

    //if this is a tuple, extract its elements as IVCs
    virtual Nullable<ImmutableTreeVector<ImplValContainer> > invertTuple(ImplValContainer possibleTuple) = 0;

    virtual ~PythonTupleConverter() {}
};

}

