// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: phone_book.proto
#ifndef GRPC_phone_5fbook_2eproto__INCLUDED
#define GRPC_phone_5fbook_2eproto__INCLUDED

#include "phone_book.pb.h"

#include <functional>
#include <grpcpp/generic/async_generic_service.h>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/client_context.h>
#include <grpcpp/completion_queue.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/proto_utils.h>
#include <grpcpp/impl/rpc_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/status.h>
#include <grpcpp/support/stub_options.h>
#include <grpcpp/support/sync_stream.h>

class PhoneBookService final {
 public:
  static constexpr char const* service_full_name() {
    return "PhoneBookService";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status addContact(::grpc::ClientContext* context, const ::Contact& request, ::google::protobuf::Empty* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::google::protobuf::Empty>> AsyncaddContact(::grpc::ClientContext* context, const ::Contact& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::google::protobuf::Empty>>(AsyncaddContactRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::google::protobuf::Empty>> PrepareAsyncaddContact(::grpc::ClientContext* context, const ::Contact& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::google::protobuf::Empty>>(PrepareAsyncaddContactRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientReaderInterface< ::Contact>> searchContact(::grpc::ClientContext* context, const ::SearchRequest& request) {
      return std::unique_ptr< ::grpc::ClientReaderInterface< ::Contact>>(searchContactRaw(context, request));
    }
    std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::Contact>> AsyncsearchContact(::grpc::ClientContext* context, const ::SearchRequest& request, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::Contact>>(AsyncsearchContactRaw(context, request, cq, tag));
    }
    std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::Contact>> PrepareAsyncsearchContact(::grpc::ClientContext* context, const ::SearchRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::Contact>>(PrepareAsyncsearchContactRaw(context, request, cq));
    }
    virtual ::grpc::Status deleteContact(::grpc::ClientContext* context, const ::DeleteRequest& request, ::google::protobuf::Empty* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::google::protobuf::Empty>> AsyncdeleteContact(::grpc::ClientContext* context, const ::DeleteRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::google::protobuf::Empty>>(AsyncdeleteContactRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::google::protobuf::Empty>> PrepareAsyncdeleteContact(::grpc::ClientContext* context, const ::DeleteRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::google::protobuf::Empty>>(PrepareAsyncdeleteContactRaw(context, request, cq));
    }
    class async_interface {
     public:
      virtual ~async_interface() {}
      virtual void addContact(::grpc::ClientContext* context, const ::Contact* request, ::google::protobuf::Empty* response, std::function<void(::grpc::Status)>) = 0;
      virtual void addContact(::grpc::ClientContext* context, const ::Contact* request, ::google::protobuf::Empty* response, ::grpc::ClientUnaryReactor* reactor) = 0;
      virtual void searchContact(::grpc::ClientContext* context, const ::SearchRequest* request, ::grpc::ClientReadReactor< ::Contact>* reactor) = 0;
      virtual void deleteContact(::grpc::ClientContext* context, const ::DeleteRequest* request, ::google::protobuf::Empty* response, std::function<void(::grpc::Status)>) = 0;
      virtual void deleteContact(::grpc::ClientContext* context, const ::DeleteRequest* request, ::google::protobuf::Empty* response, ::grpc::ClientUnaryReactor* reactor) = 0;
    };
    typedef class async_interface experimental_async_interface;
    virtual class async_interface* async() { return nullptr; }
    class async_interface* experimental_async() { return async(); }
   private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::google::protobuf::Empty>* AsyncaddContactRaw(::grpc::ClientContext* context, const ::Contact& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::google::protobuf::Empty>* PrepareAsyncaddContactRaw(::grpc::ClientContext* context, const ::Contact& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientReaderInterface< ::Contact>* searchContactRaw(::grpc::ClientContext* context, const ::SearchRequest& request) = 0;
    virtual ::grpc::ClientAsyncReaderInterface< ::Contact>* AsyncsearchContactRaw(::grpc::ClientContext* context, const ::SearchRequest& request, ::grpc::CompletionQueue* cq, void* tag) = 0;
    virtual ::grpc::ClientAsyncReaderInterface< ::Contact>* PrepareAsyncsearchContactRaw(::grpc::ClientContext* context, const ::SearchRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::google::protobuf::Empty>* AsyncdeleteContactRaw(::grpc::ClientContext* context, const ::DeleteRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::google::protobuf::Empty>* PrepareAsyncdeleteContactRaw(::grpc::ClientContext* context, const ::DeleteRequest& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());
    ::grpc::Status addContact(::grpc::ClientContext* context, const ::Contact& request, ::google::protobuf::Empty* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::google::protobuf::Empty>> AsyncaddContact(::grpc::ClientContext* context, const ::Contact& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::google::protobuf::Empty>>(AsyncaddContactRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::google::protobuf::Empty>> PrepareAsyncaddContact(::grpc::ClientContext* context, const ::Contact& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::google::protobuf::Empty>>(PrepareAsyncaddContactRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientReader< ::Contact>> searchContact(::grpc::ClientContext* context, const ::SearchRequest& request) {
      return std::unique_ptr< ::grpc::ClientReader< ::Contact>>(searchContactRaw(context, request));
    }
    std::unique_ptr< ::grpc::ClientAsyncReader< ::Contact>> AsyncsearchContact(::grpc::ClientContext* context, const ::SearchRequest& request, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncReader< ::Contact>>(AsyncsearchContactRaw(context, request, cq, tag));
    }
    std::unique_ptr< ::grpc::ClientAsyncReader< ::Contact>> PrepareAsyncsearchContact(::grpc::ClientContext* context, const ::SearchRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncReader< ::Contact>>(PrepareAsyncsearchContactRaw(context, request, cq));
    }
    ::grpc::Status deleteContact(::grpc::ClientContext* context, const ::DeleteRequest& request, ::google::protobuf::Empty* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::google::protobuf::Empty>> AsyncdeleteContact(::grpc::ClientContext* context, const ::DeleteRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::google::protobuf::Empty>>(AsyncdeleteContactRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::google::protobuf::Empty>> PrepareAsyncdeleteContact(::grpc::ClientContext* context, const ::DeleteRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::google::protobuf::Empty>>(PrepareAsyncdeleteContactRaw(context, request, cq));
    }
    class async final :
      public StubInterface::async_interface {
     public:
      void addContact(::grpc::ClientContext* context, const ::Contact* request, ::google::protobuf::Empty* response, std::function<void(::grpc::Status)>) override;
      void addContact(::grpc::ClientContext* context, const ::Contact* request, ::google::protobuf::Empty* response, ::grpc::ClientUnaryReactor* reactor) override;
      void searchContact(::grpc::ClientContext* context, const ::SearchRequest* request, ::grpc::ClientReadReactor< ::Contact>* reactor) override;
      void deleteContact(::grpc::ClientContext* context, const ::DeleteRequest* request, ::google::protobuf::Empty* response, std::function<void(::grpc::Status)>) override;
      void deleteContact(::grpc::ClientContext* context, const ::DeleteRequest* request, ::google::protobuf::Empty* response, ::grpc::ClientUnaryReactor* reactor) override;
     private:
      friend class Stub;
      explicit async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class async* async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class async async_stub_{this};
    ::grpc::ClientAsyncResponseReader< ::google::protobuf::Empty>* AsyncaddContactRaw(::grpc::ClientContext* context, const ::Contact& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::google::protobuf::Empty>* PrepareAsyncaddContactRaw(::grpc::ClientContext* context, const ::Contact& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientReader< ::Contact>* searchContactRaw(::grpc::ClientContext* context, const ::SearchRequest& request) override;
    ::grpc::ClientAsyncReader< ::Contact>* AsyncsearchContactRaw(::grpc::ClientContext* context, const ::SearchRequest& request, ::grpc::CompletionQueue* cq, void* tag) override;
    ::grpc::ClientAsyncReader< ::Contact>* PrepareAsyncsearchContactRaw(::grpc::ClientContext* context, const ::SearchRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::google::protobuf::Empty>* AsyncdeleteContactRaw(::grpc::ClientContext* context, const ::DeleteRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::google::protobuf::Empty>* PrepareAsyncdeleteContactRaw(::grpc::ClientContext* context, const ::DeleteRequest& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_addContact_;
    const ::grpc::internal::RpcMethod rpcmethod_searchContact_;
    const ::grpc::internal::RpcMethod rpcmethod_deleteContact_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status addContact(::grpc::ServerContext* context, const ::Contact* request, ::google::protobuf::Empty* response);
    virtual ::grpc::Status searchContact(::grpc::ServerContext* context, const ::SearchRequest* request, ::grpc::ServerWriter< ::Contact>* writer);
    virtual ::grpc::Status deleteContact(::grpc::ServerContext* context, const ::DeleteRequest* request, ::google::protobuf::Empty* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_addContact : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_addContact() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_addContact() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status addContact(::grpc::ServerContext* /*context*/, const ::Contact* /*request*/, ::google::protobuf::Empty* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestaddContact(::grpc::ServerContext* context, ::Contact* request, ::grpc::ServerAsyncResponseWriter< ::google::protobuf::Empty>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_searchContact : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_searchContact() {
      ::grpc::Service::MarkMethodAsync(1);
    }
    ~WithAsyncMethod_searchContact() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status searchContact(::grpc::ServerContext* /*context*/, const ::SearchRequest* /*request*/, ::grpc::ServerWriter< ::Contact>* /*writer*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestsearchContact(::grpc::ServerContext* context, ::SearchRequest* request, ::grpc::ServerAsyncWriter< ::Contact>* writer, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncServerStreaming(1, context, request, writer, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_deleteContact : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_deleteContact() {
      ::grpc::Service::MarkMethodAsync(2);
    }
    ~WithAsyncMethod_deleteContact() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status deleteContact(::grpc::ServerContext* /*context*/, const ::DeleteRequest* /*request*/, ::google::protobuf::Empty* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestdeleteContact(::grpc::ServerContext* context, ::DeleteRequest* request, ::grpc::ServerAsyncResponseWriter< ::google::protobuf::Empty>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(2, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_addContact<WithAsyncMethod_searchContact<WithAsyncMethod_deleteContact<Service > > > AsyncService;
  template <class BaseClass>
  class WithCallbackMethod_addContact : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_addContact() {
      ::grpc::Service::MarkMethodCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::Contact, ::google::protobuf::Empty>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::Contact* request, ::google::protobuf::Empty* response) { return this->addContact(context, request, response); }));}
    void SetMessageAllocatorFor_addContact(
        ::grpc::MessageAllocator< ::Contact, ::google::protobuf::Empty>* allocator) {
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(0);
      static_cast<::grpc::internal::CallbackUnaryHandler< ::Contact, ::google::protobuf::Empty>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~WithCallbackMethod_addContact() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status addContact(::grpc::ServerContext* /*context*/, const ::Contact* /*request*/, ::google::protobuf::Empty* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* addContact(
      ::grpc::CallbackServerContext* /*context*/, const ::Contact* /*request*/, ::google::protobuf::Empty* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithCallbackMethod_searchContact : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_searchContact() {
      ::grpc::Service::MarkMethodCallback(1,
          new ::grpc::internal::CallbackServerStreamingHandler< ::SearchRequest, ::Contact>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::SearchRequest* request) { return this->searchContact(context, request); }));
    }
    ~WithCallbackMethod_searchContact() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status searchContact(::grpc::ServerContext* /*context*/, const ::SearchRequest* /*request*/, ::grpc::ServerWriter< ::Contact>* /*writer*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerWriteReactor< ::Contact>* searchContact(
      ::grpc::CallbackServerContext* /*context*/, const ::SearchRequest* /*request*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithCallbackMethod_deleteContact : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_deleteContact() {
      ::grpc::Service::MarkMethodCallback(2,
          new ::grpc::internal::CallbackUnaryHandler< ::DeleteRequest, ::google::protobuf::Empty>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::DeleteRequest* request, ::google::protobuf::Empty* response) { return this->deleteContact(context, request, response); }));}
    void SetMessageAllocatorFor_deleteContact(
        ::grpc::MessageAllocator< ::DeleteRequest, ::google::protobuf::Empty>* allocator) {
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(2);
      static_cast<::grpc::internal::CallbackUnaryHandler< ::DeleteRequest, ::google::protobuf::Empty>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~WithCallbackMethod_deleteContact() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status deleteContact(::grpc::ServerContext* /*context*/, const ::DeleteRequest* /*request*/, ::google::protobuf::Empty* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* deleteContact(
      ::grpc::CallbackServerContext* /*context*/, const ::DeleteRequest* /*request*/, ::google::protobuf::Empty* /*response*/)  { return nullptr; }
  };
  typedef WithCallbackMethod_addContact<WithCallbackMethod_searchContact<WithCallbackMethod_deleteContact<Service > > > CallbackService;
  typedef CallbackService ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_addContact : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_addContact() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_addContact() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status addContact(::grpc::ServerContext* /*context*/, const ::Contact* /*request*/, ::google::protobuf::Empty* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_searchContact : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_searchContact() {
      ::grpc::Service::MarkMethodGeneric(1);
    }
    ~WithGenericMethod_searchContact() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status searchContact(::grpc::ServerContext* /*context*/, const ::SearchRequest* /*request*/, ::grpc::ServerWriter< ::Contact>* /*writer*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_deleteContact : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_deleteContact() {
      ::grpc::Service::MarkMethodGeneric(2);
    }
    ~WithGenericMethod_deleteContact() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status deleteContact(::grpc::ServerContext* /*context*/, const ::DeleteRequest* /*request*/, ::google::protobuf::Empty* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_addContact : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_addContact() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_addContact() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status addContact(::grpc::ServerContext* /*context*/, const ::Contact* /*request*/, ::google::protobuf::Empty* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestaddContact(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawMethod_searchContact : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_searchContact() {
      ::grpc::Service::MarkMethodRaw(1);
    }
    ~WithRawMethod_searchContact() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status searchContact(::grpc::ServerContext* /*context*/, const ::SearchRequest* /*request*/, ::grpc::ServerWriter< ::Contact>* /*writer*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestsearchContact(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncWriter< ::grpc::ByteBuffer>* writer, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncServerStreaming(1, context, request, writer, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawMethod_deleteContact : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_deleteContact() {
      ::grpc::Service::MarkMethodRaw(2);
    }
    ~WithRawMethod_deleteContact() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status deleteContact(::grpc::ServerContext* /*context*/, const ::DeleteRequest* /*request*/, ::google::protobuf::Empty* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestdeleteContact(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(2, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_addContact : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_addContact() {
      ::grpc::Service::MarkMethodRawCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->addContact(context, request, response); }));
    }
    ~WithRawCallbackMethod_addContact() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status addContact(::grpc::ServerContext* /*context*/, const ::Contact* /*request*/, ::google::protobuf::Empty* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* addContact(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_searchContact : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_searchContact() {
      ::grpc::Service::MarkMethodRawCallback(1,
          new ::grpc::internal::CallbackServerStreamingHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, const::grpc::ByteBuffer* request) { return this->searchContact(context, request); }));
    }
    ~WithRawCallbackMethod_searchContact() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status searchContact(::grpc::ServerContext* /*context*/, const ::SearchRequest* /*request*/, ::grpc::ServerWriter< ::Contact>* /*writer*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerWriteReactor< ::grpc::ByteBuffer>* searchContact(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_deleteContact : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_deleteContact() {
      ::grpc::Service::MarkMethodRawCallback(2,
          new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->deleteContact(context, request, response); }));
    }
    ~WithRawCallbackMethod_deleteContact() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status deleteContact(::grpc::ServerContext* /*context*/, const ::DeleteRequest* /*request*/, ::google::protobuf::Empty* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* deleteContact(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_addContact : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_addContact() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler<
          ::Contact, ::google::protobuf::Empty>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerUnaryStreamer<
                     ::Contact, ::google::protobuf::Empty>* streamer) {
                       return this->StreamedaddContact(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_addContact() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status addContact(::grpc::ServerContext* /*context*/, const ::Contact* /*request*/, ::google::protobuf::Empty* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedaddContact(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::Contact,::google::protobuf::Empty>* server_unary_streamer) = 0;
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_deleteContact : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_deleteContact() {
      ::grpc::Service::MarkMethodStreamed(2,
        new ::grpc::internal::StreamedUnaryHandler<
          ::DeleteRequest, ::google::protobuf::Empty>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerUnaryStreamer<
                     ::DeleteRequest, ::google::protobuf::Empty>* streamer) {
                       return this->StreameddeleteContact(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_deleteContact() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status deleteContact(::grpc::ServerContext* /*context*/, const ::DeleteRequest* /*request*/, ::google::protobuf::Empty* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreameddeleteContact(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::DeleteRequest,::google::protobuf::Empty>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_addContact<WithStreamedUnaryMethod_deleteContact<Service > > StreamedUnaryService;
  template <class BaseClass>
  class WithSplitStreamingMethod_searchContact : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithSplitStreamingMethod_searchContact() {
      ::grpc::Service::MarkMethodStreamed(1,
        new ::grpc::internal::SplitServerStreamingHandler<
          ::SearchRequest, ::Contact>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerSplitStreamer<
                     ::SearchRequest, ::Contact>* streamer) {
                       return this->StreamedsearchContact(context,
                         streamer);
                  }));
    }
    ~WithSplitStreamingMethod_searchContact() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status searchContact(::grpc::ServerContext* /*context*/, const ::SearchRequest* /*request*/, ::grpc::ServerWriter< ::Contact>* /*writer*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with split streamed
    virtual ::grpc::Status StreamedsearchContact(::grpc::ServerContext* context, ::grpc::ServerSplitStreamer< ::SearchRequest,::Contact>* server_split_streamer) = 0;
  };
  typedef WithSplitStreamingMethod_searchContact<Service > SplitStreamedService;
  typedef WithStreamedUnaryMethod_addContact<WithSplitStreamingMethod_searchContact<WithStreamedUnaryMethod_deleteContact<Service > > > StreamedService;
};


#endif  // GRPC_phone_5fbook_2eproto__INCLUDED