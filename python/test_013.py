import pathlib
import copy

import importlib.util

# load the module from the given file path
module_path = pathlib.Path("/home/angel/codes/personal-basic-codes/python/013.py")
spec = importlib.util.spec_from_file_location("mod013", module_path)
mod = importlib.util.module_from_spec(spec)
spec.loader.exec_module(mod)

def test_allDif_singleton_removes():
    vd = {'A': {1}, 'B': set(range(10)), 'C': {2, 3}}
    mod.allDif(vd)
    assert vd['B'] == set(range(10)) - {1}
    assert vd['C'] == {2, 3}

def test_allDif_multiple_singletons():
    vd = {'A': {1}, 'B': {2}, 'C': set(range(10))}
    mod.allDif(vd)
    assert vd['C'] == set(range(10)) - {1, 2}
    # ensure singletons remain unchanged
    assert vd['A'] == {1}
    assert vd['B'] == {2}

def test_GTValue_basic_and_edge():
    vd = {'X': set(range(10))}
    mod.GTValue(vd, 'X', 5)
    assert vd['X'] == {6, 7, 8, 9}

    vd2 = {'Y': set(range(10))}
    mod.GTValue(vd2, 'Y', 9)
    assert vd2['Y'] == set()  # removed 0..9

def test_LTValue_basic_and_edge():
    vd = {'Z': set(range(10))}
    mod.LTValue(vd, 'Z', 5)
    assert vd['Z'] == set(range(5))  # kept 0..4

    vd2 = {'W': set(range(10))}
    mod.LTValue(vd2, 'W', 0)
    assert vd2['W'] == set()  # removed 0..9