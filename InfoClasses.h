#pragma once


using namespace System;

namespace SitaForm {
    public ref class ClientInfo {
    public:
        System::String^ ID;
        System::String^ Name;

        ClientInfo(System::String^ id, System::String^ name) {
            ID = id;
            Name = name;
        }

        ClientInfo() {}

        virtual System::String^ ToString() override {
            return ID + " - " + Name;
        }
    };

    public ref class ManagerInfo {
    public:
        System::String^ ID;
        System::String^ Name;

        ManagerInfo(System::String^ id, System::String^ name) {
            ID = id;
            Name = name;
        }

        ManagerInfo() {}

        virtual System::String^ ToString() override {
            return ID + " - " + Name;
        }
    };

    public ref class EmployeeInfo {
    public:
        System::String^ ID;
        System::String^ Name;

        EmployeeInfo(System::String^ id, System::String^ name) {
            ID = id;
            Name = name;
        }

        EmployeeInfo() {}

        virtual System::String^ ToString() override {
            return ID + " - " + Name;
        }
    };
}
