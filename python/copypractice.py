import shutil
import tempfile
import os


def copyfile(src, new):
    """
    Efficient, buffered and atomic file copy.

    - Uses a 1MB buffer to avoid loading the whole file into memory.
    - Writes to a temporary file in the destination directory and
      atomically moves it into place with ``os.replace`` to avoid
      leaving a partial target on interruption.
    - Preserves file metadata (permissions/timestamps) via ``shutil.copystat``.
    """
    dst_dir = os.path.dirname(new) or "."
    tmp_path = None
    try:
        with open(src, "rb") as fsrc:
            with tempfile.NamedTemporaryFile(delete=False, dir=dst_dir) as tmpf:
                # 1MB buffer
                shutil.copyfileobj(fsrc, tmpf, length=1024 * 1024)
                tmp_path = tmpf.name

        # atomic replace
        os.replace(tmp_path, new)
        # preserve metadata
        try:
            shutil.copystat(src, new)
        except Exception:
            # don't fail the whole copy if metadata can't be copied
            pass
    except Exception:
        if tmp_path and os.path.exists(tmp_path):
            try:
                os.remove(tmp_path)
            except Exception:
                pass
        raise
# def copyfile(src,new):
#     file=open(src,"r",encoding="utf-8")
#     content=file.read()
#     file.close()
#     newfile=open(new,"w",encoding="utf-8")
#     newfile.write(content)
#     newfile.close()