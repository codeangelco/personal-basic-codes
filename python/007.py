
# Prefer setting OPENAI_API_KEY in the environment; if not set, prompt the user (safer than hardcoding)
import os
from openai import OpenAI

API_KEY = os.environ.get("OPENAI_API_KEY")
if not API_KEY:
    try:
        API_KEY = input("Enter your OpenAI API key (or set OPENAI_API_KEY env var): ").strip()
    except Exception:
        API_KEY = None
if not API_KEY:
    raise RuntimeError("Set the OPENAI_API_KEY environment variable or provide it at runtime")

client = OpenAI(api_key=API_KEY)

respuesta = client.responses.create(
    model="gpt-4o-mini",
    input="Saluda en Japonés"
)

# Intentar extraer y mostrar el texto resultante, si está disponible
try:
    texto = respuesta.output[0].content[0].text
except Exception:
    texto = None

if texto:
    print(texto)
else:
    print(respuesta)
    
    
# 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