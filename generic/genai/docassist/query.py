import chromadb
from llama_index.core import (Settings, StorageContext, VectorStoreIndex,
                              get_response_synthesizer)
from llama_index.core.memory import ChatMemoryBuffer
from llama_index.embeddings.huggingface import HuggingFaceEmbedding
from llama_index.llms.ollama import Ollama
from llama_index.vector_stores.chroma import ChromaVectorStore

#logging.basicConfig(stream=sys.stderr, level=logging.DEBUG)
#logging.getLogger().addHandler(logging.StreamHandler(stream=sys.stderr))
#llama_index.core.set_global_handler("simple")

Settings.embed_model = HuggingFaceEmbedding(
    model_name="BAAI/bge-small-en-v1.5"
)

Settings.llm = Ollama(
    model="mistral",
    request_timeout=6000.0
)

# initialize client
db = chromadb.PersistentClient(path="./chroma_db")

# get collection
chroma_collection = db.get_or_create_collection("docs")

# assign chroma as the vector_store to the context
vector_store = ChromaVectorStore(chroma_collection=chroma_collection)
storage_context = StorageContext.from_defaults(vector_store=vector_store)

# load your index from stored vectors
index = VectorStoreIndex.from_vector_store(
    vector_store, storage_context=storage_context
)

memory = ChatMemoryBuffer.from_defaults(token_limit=1500)
chat_engine = index.as_chat_engine(
    chat_mode="context",
    memory=memory,
    system_prompt=(
        "You are a chatbot, able to have normal interactions, as well as talk"
        " about rules, regulation, guidelines of a society."
    ),
)

#query_engine = index.as_query_engine()
while True:
    text_input = input("User: ")
    if text_input == "exit":
        break
    response = chat_engine.chat(text_input)
    print(f"Agent: {response}")