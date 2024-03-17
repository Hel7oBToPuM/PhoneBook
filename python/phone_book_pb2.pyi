from google.protobuf import empty_pb2 as _empty_pb2
from google.protobuf.internal import containers as _containers
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from typing import ClassVar as _ClassVar, Iterable as _Iterable, Mapping as _Mapping, Optional as _Optional, Union as _Union

DESCRIPTOR: _descriptor.FileDescriptor

class DeleteRequest(_message.Message):
    __slots__ = ("contact",)
    CONTACT_FIELD_NUMBER: _ClassVar[int]
    contact: Contact
    def __init__(self, contact: _Optional[_Union[Contact, _Mapping]] = ...) -> None: ...

class SearchRequest(_message.Message):
    __slots__ = ("contact",)
    CONTACT_FIELD_NUMBER: _ClassVar[int]
    contact: Contact
    def __init__(self, contact: _Optional[_Union[Contact, _Mapping]] = ...) -> None: ...

class Contact(_message.Message):
    __slots__ = ("phone", "first_name", "last_name", "patronymic", "note")
    PHONE_FIELD_NUMBER: _ClassVar[int]
    FIRST_NAME_FIELD_NUMBER: _ClassVar[int]
    LAST_NAME_FIELD_NUMBER: _ClassVar[int]
    PATRONYMIC_FIELD_NUMBER: _ClassVar[int]
    NOTE_FIELD_NUMBER: _ClassVar[int]
    phone: str
    first_name: str
    last_name: str
    patronymic: str
    note: str
    def __init__(self, phone: _Optional[str] = ..., first_name: _Optional[str] = ..., last_name: _Optional[str] = ..., patronymic: _Optional[str] = ..., note: _Optional[str] = ...) -> None: ...

class PhoneBook(_message.Message):
    __slots__ = ("contacts",)
    CONTACTS_FIELD_NUMBER: _ClassVar[int]
    contacts: _containers.RepeatedCompositeFieldContainer[Contact]
    def __init__(self, contacts: _Optional[_Iterable[_Union[Contact, _Mapping]]] = ...) -> None: ...
