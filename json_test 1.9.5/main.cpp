 #include <fstream>
 #include <iostream>
 #include <json/json.h>
#include <QFile>
#include <QString>
#include <QByteArray>

 void readJsonData(const std::string &jsonFilePath) {
     std::string json_data;
     QFile file(QString::fromStdString(jsonFilePath));

     if (!file.open(QIODevice::ReadOnly)) {
      std::cerr << "Failed to open JSON file: " << jsonFilePath << std::endl;
    } else {
        json_data = QString(file.readAll()).toStdString();
    }

   // 解析 JSON 数据
   Json::Value json;
   Json::Reader reader(Json::Features::strictMode());

   std::vector<double> x_mean_;
   std::vector<double> x_std_;
   std::vector<double> y_mean_;
   std::vector<double> coef_;
   std::vector<int> feature;

   if (reader.parse(json_data, json)) {
     // 将 JSON 数据解析为 std::vector<int> 类型的对象
     Json::Value array_feature = json["feature"];
     for (unsigned int i = 0; i < array_feature.size(); i++) {
       feature.push_back(array_feature[i].asInt());
     }
     // 将 JSON 数据解析为 std::vector<double> 类型的对象
     Json::Value array_x_mean = json["x_mean_"];
     for (unsigned int i = 0; i < array_x_mean.size(); i++) {
       x_mean_.push_back(array_x_mean[i].asDouble());
     }
     Json::Value array_x_std = json["x_std_"];
     for (unsigned int i = 0; i < array_x_std.size(); i++) {
       x_std_.push_back(array_x_std[i].asDouble());
     }
     Json::Value array_y_mean = json["y_mean_"];
     for (unsigned int i = 0; i < array_y_mean.size(); i++) {
       y_mean_.push_back(array_y_mean[i].asDouble());
     }
     Json::Value array_coef = json["coef_"];
     for (unsigned int i = 0; i < array_coef.size(); i++) {
       coef_.push_back(array_coef[i].asDouble());
     }
   } else {
     // 解析 JSON 数据失败
     std::cerr << "Error parsing JSON data" << std::endl;
   }
   for (unsigned int i = 0; i < coef_.size(); i++) {
       std::cout << coef_[i] << " ";
   }
   std::cout << std::endl;
 }

 int main(int, char **) {
   //   std::string strJson="{\"feature\":[1,2,3,4,5]}";
   //   Json::Reader reader(Json::Features::strictMode());
   //   Json::Value json;
   //   if (reader.parse(strJson, json)) {
   //       // 解析成功
   //       std::cout << "解析成功" << std::endl;
   //       for (unsigned int i = 0; i < json["feature"].size(); i++) {
   //           std::cout << json["feature"][i].asInt() << std::endl;
   //       }
   //   } else {
   //   std::cout << "解析失败" << std::endl;
   //   }

   readJsonData(":/tHb_model.json");
 }
