employees = []

def display_menu():
    print("--------------------------------------")
    print(" Welcome to Employee Management System")
    print("---------------------------------------")
    print("1. Add New Employee")
    print("2. View Employees")
    print("3. Search Employee")
    print("4. Update Employee")
    print("5. Delete Employee")
    print("6. Quit")

def add_employee():
    print("-------------------------")
    print("Add Employee Information")
    print("-------------------------")
    employee = {}
    employee['emp_id'] = input("Enter Employee ID: ")
    employee['name'] = input("Enter Name: ")
    employee['age'] = input("Enter Age: ")
    employee['phone'] = input("Enter Phone: ")
    employees.append(employee)
    print("Employee added successfully")

def view_employees():
    print("--- Employee Records ---")
    for employee in employees:
        print("Employee ID:", employee['emp_id'])
        print("Name:", employee['name'])
        print("Age:", employee['age'])
        print("Phone:", employee['phone'])
        print("-------------------------")

def search_employee():
    emp_id = input("Enter employee ID to search: ")
    for employee in employees:
        if employee['emp_id'] == emp_id:
            print("Employee Found:")
            print("Employee ID:", employee['emp_id'])
            print("Name:", employee['name'])
            print("Age:", employee['age'])
            print("Phone:", employee['phone'])
            return
    print("Employee not found.")

def update_employee():
    emp_id = input("Enter employee ID to update: ")
    for employee in employees:
        if employee['emp_id'] == emp_id:
            print("Update Employee Information")
            employee['name'] = input("Enter Name: ")
            employee['age'] = input("Enter Age: ")
            employee['phone'] = input("Enter Phone: ")
            print("Employee updated successfully")
            return
    print("Employee not found.")

def delete_employee():
    emp_id = input("Enter employee ID to delete: ")
    for employee in employees:
        if employee['emp_id'] == emp_id:
            employees.remove(employee)
            print("Employee deleted successfully")
            return
    print("Employee not found.")

while True:
    display_menu()
    choice = input("Enter your choice: ")

    if choice == '1':
        add_employee()
    elif choice == '2':
        view_employees()
    elif choice == '3':
        search_employee()
    elif choice == '4':
        update_employee()
    elif choice == '5':
        delete_employee()
    elif choice == '6':
        break

print("-------------------------------")
print(" Thank you for using our system")
print("-------------------------------")
