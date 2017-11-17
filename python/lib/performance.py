import cProfile

#https://zapier.com/engineering/profiling-python-boss/
def do_cprofile(func):
    def profiled_func(*args, **kwargs):
        profile = cProfile.Profile()
        try:
            profile.enable()
            result = func(*args, **kwargs)
            profile.disable()
            print("result: %s" % result)
        finally:
            profile.print_stats()
    return profiled_func
