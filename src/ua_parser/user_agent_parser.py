from . import pyuapcpp


def Parse(user_agent_string: str, **kwargs):
    ua = pyuapcpp.parse(user_agent_string)
    return {
        'user_agent': {
            "family": ua.browser.family,
            "major": ua.browser.major or None,
            "minor": ua.browser.minor or None,
            "patch": ua.browser.patch or None,
        },
        'os': {
            "family": ua.os.family,
            "major": ua.os.major or None,
            "minor": ua.os.minor or None,
            "patch": ua.os.patch or None,
            "patch_minor": ua.os.patch_minor or None,
        },
        'device': {
            "family": ua.device.family or None,
            "brand": ua.device.brand or None,
            "model": ua.device.model or None
        }
    }