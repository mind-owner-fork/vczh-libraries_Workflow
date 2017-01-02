/***********************************************************************
Vczh Library++ 3.0
Developer: Zihan Chen(vczh)
Workflow::C++ Code Generator

Interfaces:
**********************************************************************/

#ifndef VCZH_WORKFLOW_CPP_WFCPP
#define VCZH_WORKFLOW_CPP_WFCPP

#include "../Analyzer/WfAnalyzer.h"

namespace vl
{
	namespace workflow
	{
		namespace cppcodegen
		{
			class WfCppConfig : public Object
			{
			protected:
				regex::Regex										regexSplitName;
				regex::Regex										regexSpecialName;

				void												Collect();

			public:
				analyzer::WfLexicalScopeManager*					manager;
				WString												assemblyNamespace;
				WString												assemblyName;

				collections::List<Ptr<WfEnumDeclaration>>			enumDecls;
				collections::List<Ptr<WfStructDeclaration>>			structDecls;
				collections::List<Ptr<WfVariableDeclaration>>		varDecls;
				collections::List<Ptr<WfFunctionDeclaration>>		funcDecls;
				collections::List<Ptr<WfClassDeclaration>>			classDecls;
				collections::List<Ptr<WfExpression>>				lambdaExprs;
				collections::List<Ptr<WfNewInterfaceExpression>>	classExprs;

				WfCppConfig(analyzer::WfLexicalScopeManager* _manager);
				~WfCppConfig();

				WString					ConvertName(const WString& name);
				WString					WriteName(stream::StreamWriter& writer, const WString& fullName, collections::List<WString>& nss, WString& name);
				void					WriteEnd(stream::StreamWriter& writer, collections::List<WString>& nss);

				void					WriteHeader_Global(stream::StreamWriter& writer, collections::List<WString>& nss);
				void					WriteHeader_Enum(stream::StreamWriter& writer, Ptr<WfEnumDeclaration> decl, collections::List<WString>& nss);
				void					WriteHeader_Struct(stream::StreamWriter& writer, Ptr<WfStructDeclaration> decl, collections::List<WString>& nss);
				void					WriteHeader_ClassPreDecls(stream::StreamWriter& writer, collections::List<WString>& nss);
				void					WriteHeader_Class(stream::StreamWriter& writer, Ptr<WfClassDeclaration> decl, collections::List<WString>& nss);

				void					WriteCpp_Global(stream::StreamWriter& writer);
				void					WriteCpp_LambdaExprDecl(stream::StreamWriter& writer, Ptr<WfExpression> lambda, collections::List<WString>& nss);
				void					WriteCpp_LambdaExprImpl(stream::StreamWriter& writer, Ptr<WfExpression> lambda, collections::List<WString>& nss);
				void					WriteCpp_ClassExprDecl(stream::StreamWriter& writer, Ptr<WfNewInterfaceExpression> lambda, collections::List<WString>& nss);
				void					WriteCpp_ClassExprImpl(stream::StreamWriter& writer, Ptr<WfNewInterfaceExpression> lambda, collections::List<WString>& nss);
				void					GetClassMembers(Ptr<WfClassDeclaration> decl, collections::List<Ptr<WfClassMember>>& members);
				void					WriteCpp_ClassMember(stream::StreamWriter& writer, Ptr<WfClassDeclaration> decl, Ptr<WfClassMember> member, collections::List<WString>& nss);
			};

/***********************************************************************
WfCppConfig::Collect
***********************************************************************/

			extern void CollectExpression(WfCppConfig* config, Ptr<WfExpression> node);
			extern void CollectStatement(WfCppConfig* config, Ptr<WfStatement> node);
			extern void CollectClassMember(WfCppConfig* config, Ptr<WfClassMember> node);
			extern void CollectDeclaration(WfCppConfig* config, Ptr<WfDeclaration> node);
		}
	}
}

#endif