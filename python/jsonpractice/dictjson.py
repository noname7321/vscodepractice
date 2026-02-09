import json

staff_dict = {
    "name": "John",
    "age": 30,
    "city": "New York",
}

person_dict = {}
person_dict["J"] = staff_dict
person_json = json.dumps(person_dict)
print(person_json)

languages_list = ["Python", "Java", "C++"]
languages_dict = {"Natural language": "English"}
languages_dict["Programming Languages"] = languages_list
languages_json = json.dumps(languages_dict)
print(languages_json)
