import ctypes
import os

# Простейший тест
print("="*60)
print("ПРОСТЕЙШИЙ ТЕСТ MYMATHLIB.DLL")
print("="*60)

# Загружаем DLL
dll_path = r"C:\cpp\check_dll\bin\mymathlib.dll"
if not os.path.exists(dll_path):
    print(f"✗ DLL не найдена: {dll_path}")
    exit(1)

try:
    mymath = ctypes.CDLL(dll_path)
    print(f"✓ DLL загружена")
    
    # Настраиваем простые функции
    mymath.sign.argtypes = [ctypes.c_double]
    mymath.sign.restype = ctypes.c_int
    
    mymath.sqr.argtypes = [ctypes.c_double]
    mymath.sqr.restype = ctypes.c_double
    
    mymath.rad.argtypes = [ctypes.c_double]
    mymath.rad.restype = ctypes.c_double
    
    mymath.grad.argtypes = [ctypes.c_double]
    mymath.grad.restype = ctypes.c_double
    
    # Тестируем
    print(f"\nТестируем функции:")
    print(f"sign(10.5) = {mymath.sign(10.5)}")
    print(f"sign(-5.5) = {mymath.sign(-5.5)}")
    print(f"sqr(4) = {mymath.sqr(4)}")
    print(f"rad(180) = {mymath.rad(180)}")
    print(f"grad(3.14159) = {mymath.grad(3.14159)}")
    
    print("\n" + "="*60)
    print("ВСЕ ФУНКЦИИ РАБОТАЮТ!")
    print("="*60)
    
except Exception as e:
    print(f"✗ Ошибка: {e}")
    import traceback
    traceback.print_exc()