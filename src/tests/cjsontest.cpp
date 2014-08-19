#include "../test.h"
#include "cJSON/cJSON.h"

static void GenStat(Stat* s, const cJSON* v) {
    switch (v->type) {
    case cJSON_Object:    
        for (cJSON* child = v->child; child != 0; child = child->next) {
            GenStat(s, child);
            s->stringCount++;
            s->stringLength += strlen(child->string);
            s->memberCount++;
        }
        s->objectCount++;
        break;

    case cJSON_Array:
        for (cJSON* child = v->child; child != 0; child = child->next) {
            GenStat(s, child);
            s->elementCount++;
        }
        s->arrayCount++;
        break;

    case cJSON_String:
        s->stringCount++;
        s->stringLength += strlen(v->valuestring);
        break;

    case cJSON_Number:
        s->numberCount++; 
        break;

    case cJSON_True:
        s->trueCount++;
        break;

    case cJSON_False:
        s->falseCount++;
        break;

    case cJSON_NULL:
        s->nullCount++;
        break;
    }
}

class CjsonParseResult : public ParseResultBase {
public:
    CjsonParseResult() : root() {}
    ~CjsonParseResult() { cJSON_Delete(root); }

    cJSON *root;
};

class CjsonStringResult : public StringResultBase {
public:
    CjsonStringResult() : s() {}
    ~CjsonStringResult() { free(s); }

    virtual const char* c_str() const { return s; }

    char* s;
};

class CjsonTest : public TestBase {
public:
    CjsonTest() : TestBase("cJSON") {
	}
	
    virtual ParseResultBase* Parse(const char* json, size_t length) const {
        (void)length;
        CjsonParseResult* pr = new CjsonParseResult;
        pr->root = cJSON_Parse(json);
        if (!pr->root) {
            delete pr;
            return 0;
        }
    	return pr;
    }

    virtual StringResultBase* Stringify(const ParseResultBase* parseResult) const {
        const CjsonParseResult* pr = static_cast<const CjsonParseResult*>(parseResult);
        CjsonStringResult* sr = new CjsonStringResult;
        sr->s = cJSON_PrintUnformatted(pr->root);
        return sr;
    }

    virtual StringResultBase* Prettify(const ParseResultBase* parseResult) const {
        const CjsonParseResult* pr = static_cast<const CjsonParseResult*>(parseResult);
        CjsonStringResult* sr = new CjsonStringResult;
        sr->s = cJSON_Print(pr->root);
        return sr;
    }

    virtual bool Statistics(const ParseResultBase* parseResult, Stat* stat) const {
        const CjsonParseResult* pr = static_cast<const CjsonParseResult*>(parseResult);
        memset(stat, 0, sizeof(Stat));
        GenStat(stat, pr->root);
        return true;
    }
};

REGISTER_TEST(CjsonTest);
