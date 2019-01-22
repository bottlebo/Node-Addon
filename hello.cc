#include <nan.h>
using namespace std;
using namespace Nan;
using namespace v8;

void Fill(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  Local<Array> array = Local<Array>::Cast(info[0]);
  for (unsigned int i = 0; i < array->Length(); i++) {
    v8::Local<v8::Value> jsElement = Nan::New(i);

    array->Set(i, jsElement);
  }
  info.GetReturnValue().Set(array);
}

void Init(v8::Local<v8::Object> exports) {
  
  exports->Set(Nan::New("fill").ToLocalChecked(),
      Nan::New<v8::FunctionTemplate>(Fill)->GetFunction());
}

NODE_MODULE(hello, Init)
