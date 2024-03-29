// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: phone_book.proto

#include "phone_book.pb.h"
#include "phone_book.grpc.pb.h"

#include <functional>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/impl/channel_interface.h>
#include <grpcpp/impl/client_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/rpc_service_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/sync_stream.h>

static const char* PhoneBookService_method_names[] = {
  "/PhoneBookService/addContact",
  "/PhoneBookService/searchContact",
  "/PhoneBookService/deleteContact",
};

std::unique_ptr< PhoneBookService::Stub> PhoneBookService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< PhoneBookService::Stub> stub(new PhoneBookService::Stub(channel, options));
  return stub;
}

PhoneBookService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_addContact_(PhoneBookService_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_searchContact_(PhoneBookService_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::SERVER_STREAMING, channel)
  , rpcmethod_deleteContact_(PhoneBookService_method_names[2], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status PhoneBookService::Stub::addContact(::grpc::ClientContext* context, const ::Contact& request, ::google::protobuf::Empty* response) {
  return ::grpc::internal::BlockingUnaryCall< ::Contact, ::google::protobuf::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_addContact_, context, request, response);
}

void PhoneBookService::Stub::async::addContact(::grpc::ClientContext* context, const ::Contact* request, ::google::protobuf::Empty* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::Contact, ::google::protobuf::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_addContact_, context, request, response, std::move(f));
}

void PhoneBookService::Stub::async::addContact(::grpc::ClientContext* context, const ::Contact* request, ::google::protobuf::Empty* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_addContact_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::google::protobuf::Empty>* PhoneBookService::Stub::PrepareAsyncaddContactRaw(::grpc::ClientContext* context, const ::Contact& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::google::protobuf::Empty, ::Contact, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_addContact_, context, request);
}

::grpc::ClientAsyncResponseReader< ::google::protobuf::Empty>* PhoneBookService::Stub::AsyncaddContactRaw(::grpc::ClientContext* context, const ::Contact& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncaddContactRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::ClientReader< ::Contact>* PhoneBookService::Stub::searchContactRaw(::grpc::ClientContext* context, const ::SearchRequest& request) {
  return ::grpc::internal::ClientReaderFactory< ::Contact>::Create(channel_.get(), rpcmethod_searchContact_, context, request);
}

void PhoneBookService::Stub::async::searchContact(::grpc::ClientContext* context, const ::SearchRequest* request, ::grpc::ClientReadReactor< ::Contact>* reactor) {
  ::grpc::internal::ClientCallbackReaderFactory< ::Contact>::Create(stub_->channel_.get(), stub_->rpcmethod_searchContact_, context, request, reactor);
}

::grpc::ClientAsyncReader< ::Contact>* PhoneBookService::Stub::AsyncsearchContactRaw(::grpc::ClientContext* context, const ::SearchRequest& request, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncReaderFactory< ::Contact>::Create(channel_.get(), cq, rpcmethod_searchContact_, context, request, true, tag);
}

::grpc::ClientAsyncReader< ::Contact>* PhoneBookService::Stub::PrepareAsyncsearchContactRaw(::grpc::ClientContext* context, const ::SearchRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncReaderFactory< ::Contact>::Create(channel_.get(), cq, rpcmethod_searchContact_, context, request, false, nullptr);
}

::grpc::Status PhoneBookService::Stub::deleteContact(::grpc::ClientContext* context, const ::DeleteRequest& request, ::google::protobuf::Empty* response) {
  return ::grpc::internal::BlockingUnaryCall< ::DeleteRequest, ::google::protobuf::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_deleteContact_, context, request, response);
}

void PhoneBookService::Stub::async::deleteContact(::grpc::ClientContext* context, const ::DeleteRequest* request, ::google::protobuf::Empty* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::DeleteRequest, ::google::protobuf::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_deleteContact_, context, request, response, std::move(f));
}

void PhoneBookService::Stub::async::deleteContact(::grpc::ClientContext* context, const ::DeleteRequest* request, ::google::protobuf::Empty* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_deleteContact_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::google::protobuf::Empty>* PhoneBookService::Stub::PrepareAsyncdeleteContactRaw(::grpc::ClientContext* context, const ::DeleteRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::google::protobuf::Empty, ::DeleteRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_deleteContact_, context, request);
}

::grpc::ClientAsyncResponseReader< ::google::protobuf::Empty>* PhoneBookService::Stub::AsyncdeleteContactRaw(::grpc::ClientContext* context, const ::DeleteRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncdeleteContactRaw(context, request, cq);
  result->StartCall();
  return result;
}

PhoneBookService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      PhoneBookService_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< PhoneBookService::Service, ::Contact, ::google::protobuf::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](PhoneBookService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::Contact* req,
             ::google::protobuf::Empty* resp) {
               return service->addContact(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      PhoneBookService_method_names[1],
      ::grpc::internal::RpcMethod::SERVER_STREAMING,
      new ::grpc::internal::ServerStreamingHandler< PhoneBookService::Service, ::SearchRequest, ::Contact>(
          [](PhoneBookService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::SearchRequest* req,
             ::grpc::ServerWriter<::Contact>* writer) {
               return service->searchContact(ctx, req, writer);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      PhoneBookService_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< PhoneBookService::Service, ::DeleteRequest, ::google::protobuf::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](PhoneBookService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::DeleteRequest* req,
             ::google::protobuf::Empty* resp) {
               return service->deleteContact(ctx, req, resp);
             }, this)));
}

PhoneBookService::Service::~Service() {
}

::grpc::Status PhoneBookService::Service::addContact(::grpc::ServerContext* context, const ::Contact* request, ::google::protobuf::Empty* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status PhoneBookService::Service::searchContact(::grpc::ServerContext* context, const ::SearchRequest* request, ::grpc::ServerWriter< ::Contact>* writer) {
  (void) context;
  (void) request;
  (void) writer;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status PhoneBookService::Service::deleteContact(::grpc::ServerContext* context, const ::DeleteRequest* request, ::google::protobuf::Empty* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


