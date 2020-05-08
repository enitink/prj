#include "simdjson.h"
#include "rapidjson/document.h"
#include "rapidjson/document.h"

#include <string>
#include <chrono>
#include <vector>
#include <sstream>

#define TIME(X)     { \
                        auto start_time = std::chrono::high_resolution_clock::now(); \
                        if (X) \
                        {   std::cerr << #X << " - Success"; } \
                        else \
                        {   std::cerr << #X << " - Failed"; } \
                        auto end_time = std::chrono::high_resolution_clock::now(); \
                        std::chrono::duration<double> time_span = \
                            std::chrono::duration_cast<std::chrono::duration<double>>(end_time - start_time); \
                        std::cerr << std::endl << #X << " Took " << time_span.count() << " amout of time to complete" << std::endl; \
                    }

class SimdJsonTester
{
public:
    SimdJsonTester(std::string& jsonstr)
        : __jsonstr(jsonstr)
        , __sucess(true)
    {}

    bool Parse()
    {
        simdjson::error_code error;
        __parser.parse(__jsonstr).tie(__parseddata, error);
        __sucess = (error) ? false : true;
       return __sucess;
    }

    bool DisplayData(std::vector<std::string>& paths)
    {
        if (__sucess)
            print_json(__parseddata, "", paths);
        return __sucess;
    }

private:
    void print_json(simdjson::dom::element element, std::string path, std::vector<std::string>& paths)
    {
        const std::string namePrefix = (path.empty()) ? std::string() : path + ".";
        std::string name = namePrefix;
        //std::cout << std::endl << "-" <<  name;
    
        std::vector<std::string>::const_iterator itr =
                    std::find(paths.begin(), paths.end(), name);

        bool found = false;
        if (paths.end() != itr)
            found = true;

        switch (element.type())
        {
        case simdjson::dom::element_type::ARRAY:
            for (simdjson::dom::element child : simdjson::dom::array(element))
            {
                print_json(child, path, paths);
            }
            break;
        case simdjson::dom::element_type::OBJECT:
            for (simdjson::dom::key_value_pair field : simdjson::dom::object(element))
            {
                std::ostringstream sstream;
                sstream << field.key;
                name += sstream.str();
                print_json(field.value, name, paths);
                name.resize(namePrefix.size());
            }
            break;
        case simdjson::dom::element_type::INT64:
            if (found)
                std::cout << int64_t(element) << std::endl;
            break;
        case simdjson::dom::element_type::UINT64:
            if (found)
                std::cout << uint64_t(element) << std::endl;
            break;
        case simdjson::dom::element_type::DOUBLE:
            if (found)
                std::cout << double(element) << std::endl;
            break;
        case simdjson::dom::element_type::STRING:
            if (found)
                std::cout << std::string_view(element) << std::endl;
            break;
        case simdjson::dom::element_type::BOOL:
            if (found)
                std::cout << bool(element) << std::endl;
            break;
        case simdjson::dom::element_type::NULL_VALUE:
            if (found)
                std::cout << "null" << std::endl;
            break;
        }
    }

private:
    simdjson::dom::parser __parser;
    simdjson::dom::element __parseddata;
    std::string& __jsonstr;
    bool __sucess;
};

class RapidJsonTester
{
public:
    RapidJsonTester(std::string& jsonstr)
        : __jsonstr(jsonstr)
        , __sucess(true)
    {}

    bool Parse()
    {
        __sucess =  (__dpaser.Parse(__jsonstr.c_str()).HasParseError()) ? false : true;
        return __sucess; 
    }

    bool DisplayData(std::vector<std::string>& paths)
    {
        if (__sucess)
        {
            print_json(__dpaser, "", paths);
        }
        return __sucess;
    }

private:

    void print_json(rapidjson::Value& element, std::string path, std::vector<std::string>& paths)
    {
        const std::string namePrefix = (path.empty()) ? std::string() : path + ".";
        std::string name = namePrefix;
        //std::cout << std::endl << "-" <<  name;
    
        std::vector<std::string>::const_iterator itr =
                    std::find(paths.begin(), paths.end(), name);

        bool found = false;
        if (paths.end() != itr)
            found = true;

        if (element.IsArray())
        {
            for (rapidjson::SizeType i = 0; i < element.Size(); i++)
            {
                print_json(element[i], path, paths);
            }
        }
        else if (element.IsObject())
        {
            for (rapidjson::Value::MemberIterator memIter = element.MemberBegin();
                    element.MemberEnd() != memIter; ++memIter)
            {
                name += memIter->name.GetString();
                print_json(memIter->value, name, paths);
                name.resize(namePrefix.size());
            }
        }
        else if (element.IsInt64())
        {
            if (found)
                std::cout << int64_t(element.GetInt64()) << std::endl;
        }
        else if (element.IsUint64())
        {
            if (found)
                std::cout << uint64_t(element.GetUint64()) << std::endl;
        }
        else if (element.IsDouble())
        {
            if (found)
                std::cout << double(element.GetDouble()) << std::endl; 
        }
        else if (element.IsString())
        {
            if (found)
                std::cout << std::string_view(element.GetString()) << std::endl;
        }
        else if (element.IsBool())
        {
            if (found)
                std::cout << bool(element.GetBool()) << std::endl;
        }
        else if (element.IsNull())
        {
            if (found)
                std::cout << "null" << std::endl;
        }
    }

private:
    rapidjson::Document __dpaser;
    std::string& __jsonstr;
    bool __sucess;
};

int main()
{
    std::ifstream jsonfile("sv.json"); //taking file as inputstream
    std::string jsonstr;
    if(jsonfile) {
      std::ostringstream ss;
      ss << jsonfile.rdbuf(); // reading data
      jsonstr = ss.str();
    }
    SimdJsonTester simdob(jsonstr);
    //RapidJsonTester rapidob(jsonstr);

    TIME(simdob.Parse())
    //TIME(rapidob.Parse())

    std::vector<std::string> paths;
    paths.push_back("result.calculation.value.");
    paths.push_back("result.dynamic_ref_qual.value.");
    paths.push_back("result.choice_field.value.");
    paths.push_back("result.function_field.value.");
    paths.push_back("result.sys_updated_on.value.");
    paths.push_back("result.spell_check.value.");
    paths.push_back("result.reference_cascade_rule.value.");
    paths.push_back("result.reference.value.");
    paths.push_back("result.sys_updated_by.value.");
    paths.push_back("result.read_only.value.");
    paths.push_back("result.sys_created_on.value.");
    paths.push_back("result.element_reference.value.");
    paths.push_back("result.array_denormalized.value.");
    paths.push_back("result.sys_name.value.");
    paths.push_back("result.reference_key.value.");
    paths.push_back("result.reference_qual_condition.value.");
    paths.push_back("result.xml_view.value.");
    paths.push_back("result.dependent.value.");
    paths.push_back("result.internal_type.value.");
    paths.push_back("result.sys_created_by.value.");
    paths.push_back("result.element.value.");
    paths.push_back("result.max_length.value.");
    paths.push_back("result.use_dependent_field.value.");
    paths.push_back("result.delete_roles.value.");
    paths.push_back("result.active.value.");
    paths.push_back("result.choice_table.value.");
    paths.push_back("result.foreign_database.value.");
    paths.push_back("result.sys_update_name.value.");
    paths.push_back("result.unique.value.");
    paths.push_back("result.name.value.");
    paths.push_back("result.dependent_on_field.value.");
    paths.push_back("result.dynamic_creation.value.");
    paths.push_back("result.primary.value.");
    paths.push_back("result.sys_policy.value.");
    paths.push_back("result.next_element.value.");
    paths.push_back("result.virtual.value.");
    paths.push_back("result.widget.value.");
    paths.push_back("result.use_dynamic_default.value.");
    paths.push_back("result.sizeclass.value.");
    paths.push_back("result.mandatory.value.");
    paths.push_back("result.sys_class_name.value.");
    paths.push_back("result.dynamic_default_value.value.");
    paths.push_back("result.sys_id.value.");
    paths.push_back("result.write_roles.value.");
    paths.push_back("result.array.value.");
    paths.push_back("result.audit.value.");
    paths.push_back("result.read_roles.value.");
    paths.push_back("result.sys_scope.value.");
    paths.push_back("result.dynamic_creation_script.value.");
    paths.push_back("result.create_roles.value.");
    paths.push_back("result.defaultsort.value.");
    paths.push_back("result.column_label.value.");
    paths.push_back("result.comments.value.");
    paths.push_back("result.use_reference_qualifier.value.");
    paths.push_back("result.reference_floats.value.");
    paths.push_back("result.display.value.");
    paths.push_back("result.sys_mod_count.value.");
    paths.push_back("result.default_value.value.");
    paths.push_back("result.staged.value.");
    paths.push_back("result.reference_type.value.");
    paths.push_back("result.sys_package.value.");
    paths.push_back("result.attributes.value.");
    paths.push_back("result.choice.value.");
    paths.push_back("result.table_reference.value.");
    paths.push_back("result.reference_qual.value.");
    paths.push_back("result.text_index.value.");
    paths.push_back("result.function_definition.value.");

    std::cout << std::endl;
    TIME(simdob.DisplayData(paths))
    //TIME(rapidob.DisplayData(paths))

    std::cout << std::endl;
    return 0;
}