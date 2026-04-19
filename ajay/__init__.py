import inspect
import os
from . import dijkstra, prim, kruskal, bst, avl, dll, bfs, dfs, interpolation

modules = {
    "dijkstra": dijkstra,
    "prim": prim,
    "kruskal": kruskal,
    "bst": bst,
    "avl": avl,
    "dll": dll,
    "bfs": bfs,
    "dfs": dfs,
    "interpolation": interpolation
}

def getcode(name, lang="py"):
    name = name.lower()
    lang = lang.lower()

    # Python code
    if lang == "py":
        module = modules.get(name)
        if module:
            return inspect.getsource(module)

    # C code
    elif lang == "c":
        path = os.path.join(os.path.dirname(__file__), f"{name}.c")
        if os.path.exists(path):
            with open(path, "r") as f:
                return f.read()

    return "❌ Algorithm or language not found"